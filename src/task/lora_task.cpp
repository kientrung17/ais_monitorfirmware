#include "task/lora_task.h"
#include "common/common.h"
#include "common/lora_packet.h"
#include "lora_config.h"
#include "esp_log.h"

static const char *TAG = "LoraTask";

LoraTask::LoraTask() : TaskAbstract("LoraTask", 2), lastSendTimeMs(0) {}

LoraTask::~LoraTask() {}

void LoraTask::onInitProcess() {
    ESP_LOGI(TAG, "Initializing LoRa on SPI3 (VSPI)...");

    esp_err_t ret = lora.init(
        PIN_LORA_MOSI,
        PIN_LORA_MISO,
        PIN_LORA_SCK,
        PIN_LORA_NSS,
        PIN_LORA_RST,
        PIN_LORA_IRQ
    );

    if (ret == ESP_OK) {
        // Cấu hình cứng tần số và Sync Word
        lora.setFrequency(LORA_FREQUENCY);
        lora.setSyncWord(LORA_SYNC_WORD);
        lora.startReceive();
        ESP_LOGI(TAG, "LoRa initialized successfully. Frequency: %.1f MHz, Sync Word: 0x%02X", LORA_FREQUENCY, LORA_SYNC_WORD);
    } else {
        ESP_LOGE(TAG, "LoRa initialization failed!");
    }

    lastSendTimeMs = xTaskGetTickCount() * portTICK_PERIOD_MS;
}

void LoraTask::onTimer100HzProcess() {
    // Poll nhận gói tin
    processReceivedPacket();

    // Định kỳ gửi dữ liệu cảm biến (mỗi 5 giây)
    uint32_t now = xTaskGetTickCount() * portTICK_PERIOD_MS;
    if (now - lastSendTimeMs >= 5000) {
        sendSensorData();
        lastSendTimeMs = now;
    }
}

void LoraTask::onQueueSetMessageProcess(OSBase::QueueHandle queue_sem) {
    // Không sử dụng hàng đợi cho task này
}

void LoraTask::sendSensorData() {
    LoRaPacket packet = {};
    packet.zone_id = LORA_ZONE_ID;
    packet.sender_id = LORA_MONITOR_ID;
    packet.receiver_id = LORA_BRIDGE_ID;
    packet.cmd_type = CMD_TYPE_TELEMETRY;

    // Load dữ liệu thực tế/mô phỏng từ gSharedData
    packet.data.telemetry.ampe_x100 = (int16_t)(gSharedData.ampe_ch1.load() * 100);
    packet.data.telemetry.oxy_x100 = (uint16_t)(gSharedData.oxy.load() * 100);
    packet.data.telemetry.ph_x100 = (uint16_t)(gSharedData.pH.load() * 100);
    packet.data.telemetry.temp_x100 = (int16_t)(gSharedData.temperature.load() * 100);
    packet.data.telemetry.volt_x100 = (uint16_t)(gSharedData.voltage_ac.load() * 100);
    packet.data.telemetry.phase_lost = (uint8_t)gSharedData.phase_lost_mask.load();

    // Tính CRC16
    packet.crc = calculate_crc16((uint8_t*)&packet, sizeof(LoRaPacket) - sizeof(uint16_t));

    ESP_LOGI(TAG, "Sending sensor data via LoRa: ID=%d, Ampe=%.2fA, Oxy=%.2f mg/L, pH=%.2f, Temp=%.1f C, VoltAC=%.1fV, PhaseMask=%d", 
             LORA_MONITOR_ID, gSharedData.ampe_ch1.load(), gSharedData.oxy.load(), gSharedData.pH.load(),
             gSharedData.temperature.load(), gSharedData.voltage_ac.load(), gSharedData.phase_lost_mask.load());

    // Gửi gói tin
    if (lora.sendPacket((uint8_t*)&packet, sizeof(LoRaPacket))) {
        ESP_LOGI(TAG, "Sent sensor data successfully.");
    } else {
        ESP_LOGE(TAG, "Failed to send sensor data.");
    }

    // Quay lại chế độ nhận liên tục
    lora.startReceive();
}

void LoraTask::processReceivedPacket() {
    uint8_t buf[255];
    uint8_t len = lora.receivePacket(buf, sizeof(buf));
    
    if (len == sizeof(LoRaPacket)) {
        LoRaPacket *packet = (LoRaPacket*)buf;
        
        // 1. Kiểm tra CRC16
        uint16_t calc_crc = calculate_crc16(buf, sizeof(LoRaPacket) - sizeof(uint16_t));
        if (calc_crc != packet->crc) {
            ESP_LOGW(TAG, "Received packet CRC mismatch! Calc: 0x%04X, Recv: 0x%04X", calc_crc, packet->crc);
            return;
        }

        // 2. Kiểm tra Zone ID và ID thiết bị nhận
        if (packet->zone_id != LORA_ZONE_ID) {
            // Bỏ qua nếu lệch Zone ID
            return;
        }

        if (packet->receiver_id != LORA_MONITOR_ID && packet->receiver_id != 0xFF) {
            // Bỏ qua nếu không gửi đích danh cho con Monitor này hoặc không phải Broadcast
            return;
        }

        // 3. Xử lý lệnh điều khiển relay từ Bridge
        if (packet->cmd_type == CMD_TYPE_RELAY_CTRL) {
            uint8_t channel = packet->data.relay_ctrl.relay_channel;
            uint8_t state = packet->data.relay_ctrl.relay_state;

            ESP_LOGW(TAG, "RELAY COMMAND RECEIVED: Channel %d -> %s", channel, state ? "ON" : "OFF");

            // Vì Monitor 3 Pha đo dòng không có relay trực tiếp cắt tải (hoặc chỉ có Buzzer cảnh báo)
            // Ta in cảnh báo và tự động gửi lại phản hồi ACK để báo Bridge lệnh đã tới đích thành công
            vTaskDelay(pdMS_TO_TICKS(50)); // Delay nhỏ giả lập thời gian phản ứng phần cứng

            LoRaPacket ackPacket = {};
            ackPacket.zone_id = LORA_ZONE_ID;
            ackPacket.sender_id = LORA_MONITOR_ID;
            ackPacket.receiver_id = LORA_BRIDGE_ID;
            ackPacket.cmd_type = CMD_TYPE_ACK;
            ackPacket.data.ack.status = 1; // OK
            ackPacket.data.ack.relay_channel = channel;
            ackPacket.data.ack.relay_state = state;

            ackPacket.crc = calculate_crc16((uint8_t*)&ackPacket, sizeof(LoRaPacket) - sizeof(uint16_t));

            ESP_LOGI(TAG, "Sending ACK to Bridge for relay channel %d.", channel);
            lora.sendPacket((uint8_t*)&ackPacket, sizeof(LoRaPacket));
            
            // Quay lại lắng nghe
            lora.startReceive();
        }
    }
}

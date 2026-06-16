#include "common/ds18b20.h"
#include "rom/ets_sys.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

portMUX_TYPE dsMUX = portMUX_INITIALIZER_UNLOCKED;

DS18B20::DS18B20(gpio_num_t pin) : mPin(pin) {}

DS18B20::~DS18B20() {}

bool DS18B20::init() {
    gpio_config_t io_conf = {};
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_INPUT_OUTPUT_OD; // Open-drain for 1-Wire
    io_conf.pin_bit_mask = (1ULL << mPin);
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_ENABLE; // Internal pullup
    esp_err_t err = gpio_config(&io_conf);
    if (err != ESP_OK) {
        return false;
    }
    gpio_set_level(mPin, 1);
    return reset();
}

bool DS18B20::reset() {
    bool presence = false;
    portENTER_CRITICAL(&dsMUX);
    gpio_set_direction(mPin, GPIO_MODE_OUTPUT_OD);
    gpio_set_level(mPin, 0);
    ets_delay_us(480);
    gpio_set_level(mPin, 1);
    ets_delay_us(70);
    presence = (gpio_get_level(mPin) == 0);
    portEXIT_CRITICAL(&dsMUX);
    ets_delay_us(410);
    return presence;
}

void DS18B20::writeBit(bool bit) {
    portENTER_CRITICAL(&dsMUX);
    gpio_set_direction(mPin, GPIO_MODE_OUTPUT_OD);
    gpio_set_level(mPin, 0);
    if (bit) {
        ets_delay_us(6);
        gpio_set_level(mPin, 1);
        ets_delay_us(64);
    } else {
        ets_delay_us(60);
        gpio_set_level(mPin, 1);
        ets_delay_us(10);
    }
    portEXIT_CRITICAL(&dsMUX);
}

bool DS18B20::readBit() {
    bool bit = false;
    portENTER_CRITICAL(&dsMUX);
    gpio_set_direction(mPin, GPIO_MODE_OUTPUT_OD);
    gpio_set_level(mPin, 0);
    ets_delay_us(6);
    gpio_set_level(mPin, 1);
    gpio_set_direction(mPin, GPIO_MODE_INPUT);
    ets_delay_us(9);
    bit = (gpio_get_level(mPin) != 0);
    portEXIT_CRITICAL(&dsMUX);
    ets_delay_us(55);
    return bit;
}

void DS18B20::writeByte(uint8_t data) {
    for (int i = 0; i < 8; i++) {
        writeBit((data >> i) & 1);
    }
}

uint8_t DS18B20::readByte() {
    uint8_t data = 0;
    for (int i = 0; i < 8; i++) {
        if (readBit()) {
            data |= (1 << i);
        }
    }
    return data;
}

void DS18B20::startConversion() {
    if (reset()) {
        writeByte(0xCC); // Skip ROM
        writeByte(0x44); // Convert T
    }
}

bool DS18B20::readTemperature(float &temp) {
    if (!reset()) {
        return false;
    }
    writeByte(0xCC); // Skip ROM
    writeByte(0xBE); // Read Scratchpad

    uint8_t lsb = readByte();
    uint8_t msb = readByte();

    // Rest of bytes can be skipped by resetting the bus
    reset();

    int16_t raw = (msb << 8) | lsb;
    temp = raw * 0.0625f;
    return true;
}

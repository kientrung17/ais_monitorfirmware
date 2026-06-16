#include "task/sensor_measure_task.h"
#include "common/common.h"
#include "esp_err.h"
#include "esp_timer.h"
#include "driver/gpio.h"
#include "logger/loggermanager.h"
#include <cmath>

SensorMeasureTask::SensorMeasureTask()
    : TaskAbstract("SensorMeasureTask", 1) {}

SensorMeasureTask::~SensorMeasureTask() {
    if (mAdcHandle) {
        adc_oneshot_del_unit(mAdcHandle);
        mAdcHandle = nullptr;
    }
    if (mCaliHandle) {
        adc_cali_delete_scheme_line_fitting(mCaliHandle);
        mCaliHandle = nullptr;
    }
}

void SensorMeasureTask::onInitProcess() {
    LOG_INFO("SensorMeasureTask", "Init ADC hardware (Oneshot Burst)...");
    initAdc();
    initCalibration();
    initPhasePins();

    // Initialize DS18B20
    if (mDs18b20.init()) {
        LOG_INFO("SensorMeasureTask", "DS18B20 temperature sensor initialized successfully.");
        mDs18b20.startConversion();
    } else {
        LOG_ERROR("SensorMeasureTask", "DS18B20 initialization failed!");
    }

    BaseType_t ret = xTaskCreate(adcBurstTask, "AdcBurst", 4096, this, 5, nullptr);
    if (ret != pdPASS) {
        LOG_ERROR("SensorMeasureTask", "Failed to create adcBurstTask (ret=%d)", (int)ret);
    } else {
        LOG_INFO("SensorMeasureTask", "adcBurstTask spawned successfully");
    }
}

void SensorMeasureTask::onTimer100HzProcess() {
    // Left empty since sampling runs in its own FreeRTOS thread
}

void SensorMeasureTask::onQueueSetMessageProcess(OSBase::QueueHandle queue_sem) {
    // Left empty
}

void SensorMeasureTask::initAdc() {
    // Map GPIO to ESP32 ADC1 channel dynamically
    auto mapGpioToChannel = [](int pin) -> adc_channel_t {
        switch (pin) {
            case 36: return ADC_CHANNEL_0;
            case 37: return ADC_CHANNEL_1;
            case 38: return ADC_CHANNEL_2;
            case 39: return ADC_CHANNEL_3;
            case 32: return ADC_CHANNEL_4;
            case 33: return ADC_CHANNEL_5;
            case 34: return ADC_CHANNEL_6;
            case 35: return ADC_CHANNEL_7;
            default: return ADC_CHANNEL_0;
        }
    };

    mAdcChannel = mapGpioToChannel(PIN_ADC_CURRENT);
    mAdcChannelVol = mapGpioToChannel(PIN_ADC_AC_VOLTAGE);
    mAdcChannelBat = mapGpioToChannel(PIN_ADC_BATTERY);

    adc_oneshot_unit_init_cfg_t unit_cfg = {};
    unit_cfg.unit_id = ADC_UNIT_1;
    unit_cfg.ulp_mode = ADC_ULP_MODE_DISABLE;
    esp_err_t err = adc_oneshot_new_unit(&unit_cfg, &mAdcHandle);
    if (err != ESP_OK) {
        LOG_ERROR("SensorMeasureTask", "adc_oneshot_new_unit failed: 0x%x", err);
        return;
    }

    adc_oneshot_chan_cfg_t chan_cfg = {};
    chan_cfg.bitwidth = ADC_BITWIDTH_DEFAULT;
    chan_cfg.atten = ADC_ATTEN_DB_12; // 0-3.3V range

    ESP_ERROR_CHECK(adc_oneshot_config_channel(mAdcHandle, mAdcChannel, &chan_cfg));
    ESP_ERROR_CHECK(adc_oneshot_config_channel(mAdcHandle, mAdcChannelVol, &chan_cfg));
    ESP_ERROR_CHECK(adc_oneshot_config_channel(mAdcHandle, mAdcChannelBat, &chan_cfg));
    LOG_INFO("SensorMeasureTask", "ADC1 init OK: Current (GPIO %d, Ch %d), AC Voltage (GPIO %d, Ch %d), Battery (GPIO %d, Ch %d)",
             PIN_ADC_CURRENT, mAdcChannel, PIN_ADC_AC_VOLTAGE, mAdcChannelVol, PIN_ADC_BATTERY, mAdcChannelBat);
}

void SensorMeasureTask::initCalibration() {
    adc_cali_line_fitting_config_t cali_cfg = {};
    cali_cfg.unit_id = ADC_UNIT_1;
    cali_cfg.atten = ADC_ATTEN_DB_12;
    cali_cfg.bitwidth = ADC_BITWIDTH_DEFAULT;

    esp_err_t err = adc_cali_create_scheme_line_fitting(&cali_cfg, &mCaliHandle);
    if (err != ESP_OK) {
        LOG_ERROR("SensorMeasureTask", "Calibration failed (0x%x), using fallback linear", err);
        mCaliHandle = nullptr;
    } else {
        LOG_INFO("SensorMeasureTask", "ADC Calibration OK (eFuse line fitting)");
    }
}

int SensorMeasureTask::calibrateToMv(adc_channel_t ch, int raw) {
    (void)ch;
    if (mCaliHandle) {
        int mv = 0;
        if (adc_cali_raw_to_voltage(mCaliHandle, raw, &mv) == ESP_OK) {
            return mv;
        }
    }
    return raw * 3300 / 4095;
}

void SensorMeasureTask::computeAndSendRms() {
    double mean1 = 0.0, meanVol = 0.0;
    double M2_1 = 0.0, M2_Vol = 0.0;
    double sumBat = 0.0;
    int count = 0;
    int countBat = 0;

    const uint64_t WINDOW_US = 100000ULL; // 100ms
    uint64_t startUs = esp_timer_get_time();

    while ((esp_timer_get_time() - startUs) < WINDOW_US) {
        int raw1 = 0, rawVol = 0, rawBat = 0;
        esp_err_t err1 = adc_oneshot_read(mAdcHandle, mAdcChannel, &raw1);
        esp_err_t errVol = adc_oneshot_read(mAdcHandle, mAdcChannelVol, &rawVol);
        esp_err_t errBat = adc_oneshot_read(mAdcHandle, mAdcChannelBat, &rawBat);

        if (err1 == ESP_OK && errVol == ESP_OK) {
            double mv1 = (double)calibrateToMv(mAdcChannel, raw1);
            double mvVol = (double)calibrateToMv(mAdcChannelVol, rawVol);
            count++;

            // Current calculation (Welford)
            double d1a = mv1 - mean1;
            mean1 += d1a / count;
            M2_1 += d1a * (mv1 - mean1);

            // Voltage calculation (Welford)
            double dVol = mvVol - meanVol;
            meanVol += dVol / count;
            M2_Vol += dVol * (mvVol - meanVol);
        }
        if (errBat == ESP_OK) {
            double mvBat = (double)calibrateToMv(mAdcChannelBat, rawBat);
            sumBat += mvBat;
            countBat++;
        }
    }

    if (count < 2)
        return;

    float rms_mv1 = (float)std::sqrt(M2_1 / count);
    float rms_mvVol = (float)std::sqrt(M2_Vol / count);
    float avgBatMv = (countBat > 0) ? (float)(sumBat / countBat) : 0.0f;

    // Update dynamic long-term offsets
    mDcOffset1 = EMA_ALPHA * (float)mean1 + (1.0f - EMA_ALPHA) * mDcOffset1;
    mDcOffsetVol = EMA_ALPHA * (float)meanVol + (1.0f - EMA_ALPHA) * mDcOffsetVol;

    float ampe1 = rms_mv1 * AMPS_PER_MV;
    float voltAc = rms_mvVol * VOLTS_PER_MV;

    if (ampe1 < NOISE_FLOOR)
        ampe1 = 0.0f;
    if (voltAc < NOISE_FLOOR_VOL)
        voltAc = 0.0f;

    mSmoothedAmpe1 = SMOOTH_ALPHA * ampe1 + (1.0f - SMOOTH_ALPHA) * mSmoothedAmpe1;
    mSmoothedVoltageAc = SMOOTH_ALPHA * voltAc + (1.0f - SMOOTH_ALPHA) * mSmoothedVoltageAc;

    LOG_INFO("SensorMeasureTask", "DC_I=%.0fmV DC_V=%.0fmV | RMS_I=%.1fmV RMS_V=%.1fmV | Current=%.2fA Voltage=%.1fV Bat=%.0fmV [Samples=%d]",
             (float)mean1, (float)meanVol, rms_mv1, rms_mvVol, mSmoothedAmpe1, mSmoothedVoltageAc, avgBatMv, count);

    gSharedData.ampe_ch1.store(mSmoothedAmpe1, std::memory_order_relaxed);
    gSharedData.voltage_ac.store(mSmoothedVoltageAc, std::memory_order_relaxed);
    gSharedData.voltage_pin.store(avgBatMv, std::memory_order_relaxed);

    monitorPhaseLoss();
    simulateOxyPh();

    // Read DS18B20 periodically (every 5 cycles of computeAndSendRms = 1000ms)
    static uint8_t ds18b20_cycles = 0;
    ds18b20_cycles++;
    if (ds18b20_cycles >= 5) {
        ds18b20_cycles = 0;
        float temp = 25.0f;
        if (mDs18b20.readTemperature(temp)) {
            gSharedData.temperature.store(temp, std::memory_order_relaxed);
        }
        mDs18b20.startConversion();
    }
}

void SensorMeasureTask::adcBurstTask(void *arg) {
    SensorMeasureTask *self = static_cast<SensorMeasureTask *>(arg);

    vTaskDelay(pdMS_TO_TICKS(2000));
    LOG_INFO("SensorMeasureTask", "ADC burst sampling thread started");

    while (true) {
        self->computeAndSendRms();
        vTaskDelay(pdMS_TO_TICKS(200));
    }
}

void SensorMeasureTask::initPhasePins() {
    LOG_INFO("SensorMeasureTask", "Initializing Phase loss detection pins...");
    gpio_config_t io_conf = {};
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_INPUT;
    io_conf.pin_bit_mask = (1ULL << PIN_GPIO_PHASE_1) | (1ULL << PIN_GPIO_PHASE_2) | (1ULL << PIN_GPIO_PHASE_3);
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_ENABLE;
    gpio_config(&io_conf);
    LOG_INFO("SensorMeasureTask", "Phase pins (GPIO %d, %d, %d) initialized successfully.", PIN_GPIO_PHASE_1, PIN_GPIO_PHASE_2, PIN_GPIO_PHASE_3);
}

void SensorMeasureTask::monitorPhaseLoss() {
    bool lost1 = gpio_get_level((gpio_num_t)PIN_GPIO_PHASE_1) == 1;
    bool lost2 = gpio_get_level((gpio_num_t)PIN_GPIO_PHASE_2) == 1;
    bool lost3 = gpio_get_level((gpio_num_t)PIN_GPIO_PHASE_3) == 1;

    gSharedData.is_lost_phase1.store(lost1, std::memory_order_relaxed);
    gSharedData.is_lost_phase2.store(lost2, std::memory_order_relaxed);
    gSharedData.is_lost_phase3.store(lost3, std::memory_order_relaxed);

    uint32_t mask = 0;
    if (lost1) mask |= 1;
    if (lost2) mask |= 2;
    if (lost3) mask |= 4;
    gSharedData.phase_lost_mask.store(mask, std::memory_order_relaxed);

    bool is_lost_electric = (mask != 0);
    gSharedData.is_lost_electric.store(is_lost_electric, std::memory_order_relaxed);

    LOG_DEBUG("SensorMeasureTask", "Phase loss status - Mask: %d (P1: %d, P2: %d, P3: %d), Lost Electric: %d",
             mask, lost1, lost2, lost3, is_lost_electric);
}

void SensorMeasureTask::simulateOxyPh() {
    // Time variable based on ESP32 uptime (seconds)
    double t = esp_timer_get_time() / 1000000.0;
    
    // Use a 10-minute cycle (600 seconds) for simulation testing
    double omega = 2.0 * M_PI / 600.0;
    
    // Add small random noise to simulate natural fluctuations
    double noise_ph = (((double)rand() / RAND_MAX) - 0.5) * 0.05; // -0.025 to 0.025
    double noise_oxy = (((double)rand() / RAND_MAX) - 0.5) * 0.1; // -0.05 to 0.05
    
    // pH(t) = 8.0 + 0.4 * sin(omega * t) + noise
    double simulated_ph = 8.0 + 0.4 * std::sin(omega * t) + noise_ph;
    // Oxy(t) = 6.25 + 1.1 * sin(omega * t - PI/2) + noise
    double simulated_oxy = 6.25 + 1.1 * std::sin(omega * t - M_PI_2) + noise_oxy;

    // Constrain values within limits
    if (simulated_ph < 7.5) simulated_ph = 7.5;
    if (simulated_ph > 8.5) simulated_ph = 8.5;
    if (simulated_oxy < 5.0) simulated_oxy = 5.0;
    if (simulated_oxy > 7.5) simulated_oxy = 7.5;

    gSharedData.pH.store((float)simulated_ph, std::memory_order_relaxed);
    gSharedData.oxy.store((float)simulated_oxy, std::memory_order_relaxed);

    LOG_DEBUG("SensorMeasureTask", "Simulated values - pH: %.2f, Oxy: %.2f mg/L", simulated_ph, simulated_oxy);
}

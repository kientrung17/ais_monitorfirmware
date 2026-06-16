#ifndef SENSOR_MEASURE_TASK_H_
#define SENSOR_MEASURE_TASK_H_

#include "architectureabs/taskabstract.h"
#include "esp_adc/adc_cali.h"
#include "esp_adc/adc_cali_scheme.h"
#include "esp_adc/adc_oneshot.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "common/ds18b20.h"

class SensorMeasureTask : public TaskAbstract
{
public:
    SensorMeasureTask();
    virtual ~SensorMeasureTask();

    void onTimer100HzProcess() override;
    void onQueueSetMessageProcess(OSBase::QueueHandle queue_sem) override;
    void onInitProcess() override;

private:
    adc_oneshot_unit_handle_t mAdcHandle{nullptr};
    adc_cali_handle_t mCaliHandle{nullptr};
    adc_channel_t mAdcChannel{ADC_CHANNEL_0};
    adc_channel_t mAdcChannelVol{ADC_CHANNEL_4}; // GPIO32
    adc_channel_t mAdcChannelBat{ADC_CHANNEL_7}; // GPIO35

    float mDcOffset1{1650.0f};
    float mDcOffsetVol{1650.0f};
    static constexpr float EMA_ALPHA = 0.005f;
    static constexpr float AMPS_PER_MV = 20.0f / 1000.0f;  // 20A / 1V (1000mV)
    static constexpr float VOLTS_PER_MV = 220.0f / 1000.0f; // Calibration for ZMPT101B: 220V per 1000mV RMS (0.22f)
    static constexpr float NOISE_FLOOR = 0.08f;
    static constexpr float NOISE_FLOOR_VOL = 2.0f;          // 2V AC noise floor
    float mSmoothedAmpe1{0.0f};
    float mSmoothedVoltageAc{0.0f};
    static constexpr float SMOOTH_ALPHA = 0.3f;

    void initAdc();
    void initCalibration();
    int calibrateToMv(adc_channel_t ch, int raw);
    void computeAndSendRms();

    void initPhasePins();
    void monitorPhaseLoss();
    void simulateOxyPh();

    static void adcBurstTask(void *arg);

    DS18B20 mDs18b20{GPIO_NUM_21};
};

#endif /* SENSOR_MEASURE_TASK_H_ */

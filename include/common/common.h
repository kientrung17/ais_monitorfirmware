#ifndef COMMON_H_
#define COMMON_H_

#include "stdbool.h"
#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_LENGTH_TASK_NAME 16
#define MAX_TASK 5
#define FREQUENCE_TIMER_READ_ADC 1000 // 1khz
void processTimer100Hz();

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

#include "OSFreeRTOS.h"
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "loggermanager.h"
#include <atomic>
#include <string>

// GPIO Relay (Nếu Monitor cần điều khiển còi/cảnh báo)
#define PIN_GPIO_BUZZER 14

// GPIO phát hiện pha điện
#define PIN_GPIO_PHASE_1 33
#define PIN_GPIO_PHASE_2 25
#define PIN_GPIO_PHASE_3 26

// Chân sạc Pin mạch Monitor
//#define PIN_GPIO_CHARGE_PIN 15

// ADC Sensors
#define PIN_ADC_CURRENT 39   // Đo dòng điện (Ampe)
#define PIN_ADC_OXY 36       // Đo nồng độ Oxy
#define PIN_ADC_PH 34        // Đo độ pH
#define PIN_ADC_BATTERY 35   // Đo điện áp pin dự phòng
#define PIN_ADC_AC_VOLTAGE 32 // Đo điện áp xoay chiều AC (ZMPT101B)

extern OSBase *mOSBase;

struct SharedDataStore {
  std::atomic<float> ampe_ch1{0.0f};
  std::atomic<float> oxy{0.0f};
  std::atomic<float> pH{0.0f};
  std::atomic<float> voltage_pin{0.0f};
  std::atomic<float> voltage_ac{0.0f};   // Điện áp xoay chiều lưới điện AC (V)
  std::atomic<float> temperature{25.0f}; // Mặc định 25 độ C hoặc đọc từ cảm biến

  // Trạng thái mất pha đo tại Monitor
  std::atomic<bool> is_lost_phase1{false};
  std::atomic<bool> is_lost_phase2{false};
  std::atomic<bool> is_lost_phase3{false};
  std::atomic<bool> is_lost_electric{false};
  std::atomic<uint32_t> phase_lost_mask{0}; // Bitmask (0-7)
};

extern SharedDataStore gSharedData;
extern uint32_t gMonitorDeviceID; // ID của con Monitor này (ví dụ: 1)

void initSystem();

#endif // __cplusplus

#endif /* COMMON_H_ */

#include "common/common.h"
#include "OSFreeRTOS.h"
#include "architectureabs/taskmanager.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// Danh sách tên các task cần được bảo vệ khỏi taskfreezer
static const char* MONITOR_PROTECTED_TASK_NAMES[] = {
    "SensorMeasureTa",  // FreeRTOS truncates to 16 chars
    "LoraTask",
    nullptr
};

static void resumeSuspendedProtectedTasks() {
    UBaseType_t numTasks = uxTaskGetNumberOfTasks();
    TaskStatus_t* taskArray = (TaskStatus_t*)pvPortMalloc(numTasks * sizeof(TaskStatus_t));
    if (!taskArray) return;
    uint32_t totalRunTime = 0;
    UBaseType_t filled = uxTaskGetSystemState(taskArray, numTasks, &totalRunTime);
    for (UBaseType_t i = 0; i < filled; i++) {
        if (taskArray[i].eCurrentState == eSuspended) {
            for (int j = 0; MONITOR_PROTECTED_TASK_NAMES[j] != nullptr; j++) {
                if (strncmp(taskArray[i].pcTaskName, MONITOR_PROTECTED_TASK_NAMES[j], configMAX_TASK_NAME_LEN - 1) == 0) {
                    ESP_LOGW("WDT_RESUMER", "Task '%s' Suspended by taskfreezer! Resuming...", taskArray[i].pcTaskName);
                    vTaskResume(taskArray[i].xHandle);
                    break;
                }
            }
        }
    }
    vPortFree(taskArray);
}

static void watchdogTask(void *arg) {
    while (1) {
        vTaskDelay(pdMS_TO_TICKS(1000));
        resumeSuspendedProtectedTasks();
    }
}

extern "C" void startWatchdogTask() {
    xTaskCreate(watchdogTask, "WdtResumer", 2048, nullptr, 22, nullptr);
}

SharedDataStore gSharedData;
uint32_t gMonitorDeviceID = 1; // ID của mạch Monitor này
OSBase *mOSBase = nullptr;

void initSystem() {
    mOSBase = new OSFreeRTOS();
    mOSBase->isStarted();
}

void processTimer100Hz() {
    // Gọi định kỳ từ timer ISR nếu có logic tính toán tần số cao
    TaskManager::getInstance()->onTimer100Hz();
}

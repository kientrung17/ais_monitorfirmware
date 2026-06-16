#include "common/common.h"
#include "OSFreeRTOS.h"
#include "architectureabs/taskmanager.h"

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

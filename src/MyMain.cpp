#include "MyMain.h"
#include "common/common.h"
#include "logger/loggermanager.h"
#include "task/sensor_measure_task.h"
#include "task/lora_task.h"
#include "architectureabs/taskmanager.h"

#define ID_SENSOR_MEASURE_TASK 5
#define ID_LORA_TASK 6

SensorMeasureTask* mSensorTask = nullptr;
LoraTask* mLoraTask = nullptr;

void StartSensorMeasureTask(void *argument) {
    if (mSensorTask) {
        LOG_INFO("MyMain", "Start Task Sensor Measure");
        mSensorTask->onStartProcess();
    } else {
        LOG_ERROR("MyMain", "Start Task Sensor Measure Error");
    }
}

void StartLoraTask(void *argument) {
    if (mLoraTask) {
        LOG_INFO("MyMain", "Start Task LoRa");
        mLoraTask->onStartProcess();
    } else {
        LOG_ERROR("MyMain", "Start Task LoRa Error");
    }
}

void startAllTask() {
    LOG_INFO("MyMain", "**************** Starting Monitor Skeleton ****************");
    initSystem();
    
    mSensorTask = new SensorMeasureTask();
    mLoraTask = new LoraTask();

    bool success = true;
    success &= mOSBase->taskCreate((char *)"SensorMeasureTask",
                                   (TaskProc)StartSensorMeasureTask, OSBase::PRIORITY_NORMAL,
                                   4096, ID_SENSOR_MEASURE_TASK);

    success &= mOSBase->taskCreate((char *)"LoraTask",
                                   (TaskProc)StartLoraTask, OSBase::PRIORITY_NORMAL,
                                   4096, ID_LORA_TASK);

    if (success) {
        LOG_INFO("MyMain", "Start All Task Success");
    } else {
        LOG_ERROR("MyMain", "Start All Task Error");
    }
}


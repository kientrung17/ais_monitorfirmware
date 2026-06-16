#ifndef LORA_TASK_H_
#define LORA_TASK_H_

#include "architectureabs/taskabstract.h"
#include "sx127x.h"

class LoraTask : public TaskAbstract {
public:
    LoraTask();
    virtual ~LoraTask();

    void onTimer100HzProcess() override;
    void onQueueSetMessageProcess(OSBase::QueueHandle queue_sem) override;
    void onInitProcess() override;

private:
    SX127x lora;
    uint32_t lastSendTimeMs;

    void sendSensorData();
    void processReceivedPacket();
};

#endif /* LORA_TASK_H_ */

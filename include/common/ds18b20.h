#ifndef DS18B20_H_
#define DS18B20_H_

#include <stdint.h>
#include <stdbool.h>
#include "driver/gpio.h"

#ifdef __cplusplus
extern "C" {
#endif

class DS18B20 {
public:
    DS18B20(gpio_num_t pin);
    ~DS18B20();

    bool init();
    void startConversion();
    bool readTemperature(float &temp);

private:
    gpio_num_t mPin;

    bool reset();
    void writeBit(bool bit);
    bool readBit();
    void writeByte(uint8_t data);
    uint8_t readByte();
};

#ifdef __cplusplus
}
#endif

#endif /* DS18B20_H_ */

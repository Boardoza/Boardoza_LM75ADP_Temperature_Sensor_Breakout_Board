#ifndef LM75A_h
#define LM75A_h

#include <Wire.h>
#include <Arduino.h>

#define LM75A_ADDRESS 0x48 // raw address
#define TEMP_READ_REG 0x00 // temperature read register
#define CONFIG_REG 0x01
#define TEMP_HYSTERESIS 0x02
#define OVERTEMP_SHUTDOWN 0x03
#define PRODUCT_ID_REG 0x07

class LM75A {
public:
    enum DeviceMode {
        shutdownMode = 0x01,
        compIntMode = 0x02,
        osPolarityMode = 0x04,
        faultQueue = 0x18
    };

    void begin();
    void setTempThreshold(float tempThreshold, float shutdown_Threshold);
    void setCompIntPolarityMode(uint8_t mode, uint8_t polarity);
    float readTemperature(); // to read raw temperature data in celsius
    float readTemperatureInFahrenheit(); // to read temperature in fahrenheit
    float readTemperatureInKelvin(); // to read temperature in kelvin
    float degreesToFahrenheit(float temperature); // convert celsius degree value to fahrenheit
    float fahrenheitToDegrees(float temperature); // convert fahrenheit value to celsius degree
    float degreesToKelvin(float temperature); // convert celsius degree value to kelvin
    float kelvinToDegrees(float temperature); // convert kelvin value to celsius degree
    float fahrenheitToKelvin(float temperature); // convert fahrenheit value to kelvin
    float kelvinToFahrenheit(float temperature); // convert kelvin value to fahrenheit
    
private:
    uint8_t lm75aAddress;
    DeviceMode mode;
    float readTempRegister(uint8_t reg, uint8_t lm75aAddress);
    void readRegister(uint8_t reg, uint8_t lm75aAddress);
    void writeRegister(uint8_t reg, uint8_t value);
};

#endif
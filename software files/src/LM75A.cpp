#include "LM75A.h"

uint16_t lm75aAddress = LM75A_ADDRESS;

/**
 * @brief Initializes the LM75A sensor with default I2C pins.
 * 
 * This function initializes the LM75A sensor using I2C pins.
 * It sets the I2C address of the sensor to the default value (LM75A_ADDRESS) and starts the I2C communication.
 * 
 * @note This function assumes that the I2C pins (SDA and SCL) are already configured as inputs and pulled up externally.
 */
void LM75A::begin() {
    Wire.begin();
    lm75aAddress = LM75A_ADDRESS;
}

void LM75A::setTempThreshold(float tempThreshold, float shutdown_Threshold) {

    uint8_t temp_data_h = 0;
    uint8_t temp_data_l = 0;
    uint16_t temp_test = (uint16_t)(shutdown_Threshold * 2);   // temp_threshold yerine shutdown_threshold
    temp_data_h = temp_test >> 1;
    temp_data_l = temp_test << 7;                                                                       

    Wire.beginTransmission(lm75aAddress);
    Wire.write(OVERTEMP_SHUTDOWN);
    Wire.write(temp_data_h);
    Wire.write(temp_data_l);
    Wire.endTransmission(true);

    temp_test = (uint16_t)(tempThreshold * 2);
    temp_data_h = temp_test >> 1;
    temp_data_l = temp_test << 7;

    Wire.beginTransmission(lm75aAddress);
    Wire.write(TEMP_HYSTERESIS);
    Wire.write(temp_data_h);
    Wire.write(temp_data_l);
    Wire.endTransmission(true);
}

void LM75A::setCompIntPolarityMode(uint8_t mode, uint8_t polarity) {
    Wire.beginTransmission(lm75aAddress);
    Wire.write(CONFIG_REG);
    Wire.write(mode | polarity);
    Wire.endTransmission(true);
}


/**
 * @brief Reads the temperature from the LM75A sensor.
 *
 * This function reads the raw temperature data from the LM75A sensor by reading the temperature register (TEMP_READ_REG) using the specified I2C address (lm75aAddress).
 * The raw temperature data is then converted to a floating-point temperature value using the convertToTemperature() function.
 * The calculated temperature value is returned by the function.
 *
 * @note Ensure that the LM75A sensor is properly initialized and connected before calling this function.
 *
 * @return The temperature value read from the LM75A sensor, in degrees Celsius.
 */
float LM75A::readTemperature() {
    //float temperature = readTempRegister(TEMP_READ_REG, lm75aAddress);
    
    //return temperature;
    return readTempRegister(TEMP_READ_REG, lm75aAddress);
}

/**
 * @brief Reads the temperature from the LM75A sensor and returns the value in Fahrenheit.
 *
 * This function reads the temperature value in Celsius from the LM75A sensor using the readTemperature() function.
 * It then converts the temperature value from Celsius to Fahrenheit using the formula: (celsius * 9.0 / 5.0) + 32.0.
 * The converted temperature value in Fahrenheit is returned by the function.
 *
 * @note Ensure that the LM75A sensor is properly initialized and connected before calling this function.
 *
 * @return The temperature value read from the LM75A sensor, in degrees Fahrenheit.
 */
float LM75A::readTemperatureInFahrenheit() {
    float celsius = readTemperature();
    return (celsius * 9.0 / 5.0) + 32.0;
}

/**
 * @brief Reads the temperature from the LM75A sensor and returns the value in Kelvin.
 *
 * This function reads the temperature value in Celsius from the LM75A sensor using the readTemperature() function.
 * It then adds the temperature value in Celsius to 273.15 to convert it to Kelvin.
 * The converted temperature value in Kelvin is returned by the function.
 *
 * @note Ensure that the LM75A sensor is properly initialized and connected before calling this function.
 *
 * @return The temperature value read from the LM75A sensor, in Kelvin.
 */
float LM75A::readTemperatureInKelvin() {
    float celsius = readTemperature();
    return celsius + 273.15;
}

/**
 * @brief Reads a 16-bit register value from the LM75A sensor.
 *
 * This function reads a 16-bit register value from the LM75A sensor using the specified register address (reg) and I2C address (lm75aAddress).
 * It begins the I2C transmission to the LM75A sensor with the specified address, writes the register address, and ends the transmission.
 * Then, it requests 2 bytes of data from the LM75A sensor using the specified I2C address, and combines the received bytes into a 16-bit value.
 * The 16-bit register value is returned by the function.
 *
 * @note Ensure that the LM75A sensor is properly initialized and connected before calling this function.
 *
 * @param reg The register address to read from the LM75A sensor.
 * @param lm75aAddress The I2C address of the LM75A sensor.
 * 
 * @return The 16-bit register value read from the LM75A sensor.
 */
float LM75A::readTempRegister(uint8_t reg, uint8_t lm75aAddress) {
    Wire.beginTransmission(lm75aAddress);
    Wire.write(reg);
    Wire.endTransmission(false);

    Wire.requestFrom(lm75aAddress, (uint8_t)2);

    float temperature = ((Wire.read() << 1) | (Wire.read() >> 7));
    
    return (float)(temperature) / 2;
}

/**
 * @brief Converts a temperature value from degrees Celsius to degrees Fahrenheit.
 *
 * This function takes a temperature value in degrees Celsius and converts it to degrees Fahrenheit using the formula: (temperature * 9.0 / 5.0) + 32.0.
 * The converted temperature value in degrees Fahrenheit is returned by the function.
 *
 * @param temperature The temperature value in degrees Celsius to be converted.
 *
 * @return The temperature value converted to degrees Fahrenheit.
 */
float LM75A::degreesToFahrenheit(float temperature) {
    return (temperature * 9.0 / 5.0) + 32.0;
}

/**
 * @brief Converts a temperature value from degrees Fahrenheit to degrees Celsius.
 *
 * This function takes a temperature value in degrees Fahrenheit and converts it to degrees Celsius using the formula: (temperature - 32.0) * (5.0 / 9.0).
 * The converted temperature value in degrees Celsius is returned by the function.
 *
 * @param temperature The temperature value in degrees Fahrenheit to be converted.
 *
 * @return The temperature value converted to degrees Celsius.
 */
float LM75A::fahrenheitToDegrees(float temperature) {
    return (temperature - 32.0) * (5.0 / 9.0);
}

/**
 * @brief Converts a temperature value from degrees Celsius to Kelvin.
 *
 * This function takes a temperature value in degrees Celsius and converts it to Kelvin by adding 273.15.
 * The converted temperature value in Kelvin is returned by the function.
 *
 * @param temperature The temperature value in degrees Celsius to be converted.
 *
 * @return The temperature value converted to Kelvin.
 */
float LM75A::degreesToKelvin(float temperature) {
    return temperature + 273.15;
}

/**
 * @brief Converts a temperature value from Kelvin to degrees Celsius.
 *
 * This function takes a temperature value in Kelvin and converts it to degrees Celsius by subtracting 273.15.
 * The converted temperature value in degrees Celsius is returned by the function.
 *
 * @param temperature The temperature value in Kelvin to be converted.
 *
 * @return The temperature value converted to degrees Celsius.
 */
float LM75A::kelvinToDegrees(float temperature) {
    return temperature - 273.15;
}

/**
 * @brief Converts a temperature value from degrees Fahrenheit to Kelvin.
 *
 * This function takes a temperature value in degrees Fahrenheit and converts it to Kelvin using the formula: (temperature - 32) * 5 / 9 + 273.15.
 * The converted temperature value in Kelvin is returned by the function.
 *
 * @param temperature The temperature value in degrees Fahrenheit to be converted.
 *
 * @return The temperature value converted to Kelvin.
 */
float LM75A::fahrenheitToKelvin(float temperature) {
    return (temperature - 32) * 5 / 9 + 273.15;  
}

/**
 * @brief Converts a temperature value from Kelvin to degrees Fahrenheit.
 *
 * This function takes a temperature value in Kelvin and converts it to degrees Fahrenheit using the formula: (temperature - 273.15) * 9 / 5 + 32.
 * The converted temperature value in degrees Fahrenheit is returned by the function.
 *
 * @param temperature The temperature value in Kelvin to be converted.
 *
 * @return The temperature value converted to degrees Fahrenheit.
 */
float LM75A::kelvinToFahrenheit(float temperature) {
    return (temperature - 273.15) * 9 / 5 + 32;
}

/**
 * @brief Reads a register from the LM75A temperature sensor.
 *
 * @param reg The register address to read from.
 * @param lm75aAddress The I2C address of the LM75A sensor.
 *
 * @details This function begins an I2C transmission to the LM75A sensor at the specified address,
 * writes the register address to be read, and requests 1 byte of data from that register.
 */
void LM75A::readRegister(uint8_t reg, uint8_t lm75aAddress) {
    Wire.beginTransmission(lm75aAddress);
    Wire.write(reg);
    Wire.endTransmission(false);
  
    Wire.requestFrom(lm75aAddress, 1u);

}

/**
 * @brief Writes a value to a register in the LM75A temperature sensor.
 *
 * @param reg The register address to write to.
 * @param value The value to write to the register.
 *
 * @details This function begins an I2C transmission to the LM75A sensor at the specified address,
 * writes the register address and the value to be written, and ends the transmission with or without
 * releasing the bus based on the parameter value.
 */
void LM75A::writeRegister(uint8_t reg, uint8_t value) {
        Wire.beginTransmission(lm75aAddress);
        Wire.write(reg);
        Wire.write(value);
        Wire.endTransmission(true); 
}
#include "LM75A.h"

LM75A temperature;

void setup() {
    Serial.begin(115200); 
    while (!Serial) {
        delay(10); // Waiting for serial to open
    }

    Serial.println("LM75A initializing.");

    temperature.begin();
    temperature.setCompIntPolarityMode(0, 0); // Comparator / Polarity = 0
    temperature.setTempThreshold(29, 31.50);  
    delay(10);

}

void loop() {
    float temp = temperature.readTemperature();
    Serial.println(temp);

    delay(10);
} 


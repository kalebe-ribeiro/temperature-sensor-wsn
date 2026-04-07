#include <Arduino.h>
#include "sensor.h"

void sensor_alert(float humidity, float temperature) {
    if (humidity > THRESHOLD_HUMIDITY){
        Serial.printf("Humidity has exceeded the threshold! %.2f%%\t", humidity);
    }
    if (temperature > THRESHOLD_TEMPERATURE){
        Serial.printf("Temperature has exceeded the threshold! %.2f°C\n", temperature);
    }
  
}
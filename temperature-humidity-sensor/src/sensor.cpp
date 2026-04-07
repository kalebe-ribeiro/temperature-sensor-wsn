#include <Arduino.h>
#include "sensor.h"

void sensor_alert(float humidity, float temperature) {
    if (humidity > THRESHOLD_HUMIDITY){
        Serial.println("Humidity has exceeded the threshold!\t");
        Serial.println(humidity);
        Serial.println("%");
    }

    if (temperature > THRESHOLD_TEMPERATURE){
        Serial.println("Temperature has exceeded the threshold!\t");
        Serial.println(temperature);
        Serial.println("°C");
    }
  
}
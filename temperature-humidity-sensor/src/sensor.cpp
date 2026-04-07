#include <Arduino.h>
#include "sensor.h"

AlertValues sensor_alert(float humidity, float temperature) {
    AlertValues alertValues;
    alertValues.alert_humidity = false;
    alertValues.alert_temperature = false;

    if (humidity > THRESHOLD_HUMIDITY){
        Serial.printf("Humidity has exceeded the threshold! %.2f%%\t", humidity);
        alertValues.alert_humidity = true;
    }
    if (temperature > THRESHOLD_TEMPERATURE){
        Serial.printf("Temperature has exceeded the threshold! %.2f°C\n", temperature);
        alertValues.alert_temperature = true;
    }
    return alertValues;
}
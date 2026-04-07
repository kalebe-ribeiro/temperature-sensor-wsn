#include <Arduino.h>
#include "sensor.h"

AlertValues sensor_alert(float humidity, float temperature) {
    AlertValues alertValues;
    alertValues.alert_humidity = false;
    alertValues.alert_temperature = false;

    if (humidity > THRESHOLD_HUMIDITY){
        alertValues.alert_humidity = true;
    }
    if (temperature > THRESHOLD_TEMPERATURE){
        alertValues.alert_temperature = true;
    }
    return alertValues;
}
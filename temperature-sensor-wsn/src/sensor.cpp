#include <Arduino.h>
#include "sensor.h"

AlertValues sensor_alert(float temperature) {
    AlertValues alertValues;
    alertValues.alert_temperature = false;

    if (temperature > THRESHOLD_TEMPERATURE){
        alertValues.alert_temperature = true;
    }
    return alertValues;
}

SensorData read_sensor() {
    SensorData sensorData;
    sensorData.temperature = sensors.getTempCByIndex(0);
    return sensorData;
}

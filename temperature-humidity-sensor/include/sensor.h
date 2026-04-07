#pragma once

#define THRESHOLD_HUMIDITY 60.0
#define THRESHOLD_TEMPERATURE 30.0

typedef struct {
    bool alert_humidity;
    bool alert_temperature;
} AlertValues;

typedef struct {
    float humidity;
    float temperature;
} SensorData;

AlertValues sensor_alert(float humidity, float temperature);
SensorData read_sensor();



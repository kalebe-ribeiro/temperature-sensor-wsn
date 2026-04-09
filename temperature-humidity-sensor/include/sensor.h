#pragma once

#define THRESHOLD_TEMPERATURE 30.0

typedef struct {
    bool alert_temperature;
} AlertValues;

typedef struct {
    float temperature;
} SensorData;

AlertValues sensor_alert(float temperature);
SensorData read_sensor();



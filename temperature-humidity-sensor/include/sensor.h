#pragma once

#define THRESHOLD_HUMIDITY 60.0
#define THRESHOLD_TEMPERATURE 30.0

void sensor_alert(float humidity, float temperature);
typedef struct {
    float humidity;
    float temperature;
} SensorData;

typedef struct {
    bool alert_humidity;
    bool alert_temperature;
} AlertValues;
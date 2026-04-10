#pragma once
#include "sensor.h"
#define BUFFER_SIZE 5


typedef struct{
    SensorData readings[BUFFER_SIZE];
    int head;
    int count;

} SensorBuffer;

void buffer_push(SensorBuffer* buffer, SensorData reading);
float buffer_avg_temp(const SensorBuffer *buffer);
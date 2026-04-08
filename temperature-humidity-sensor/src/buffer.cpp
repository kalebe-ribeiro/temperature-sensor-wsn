#include <Arduino.h>
#include "buffer.h"

void buffer_push(SensorBuffer* buffer, SensorData reading) {
    buffer->readings[buffer->head] = reading;
    buffer->head = (buffer->head + 1) % BUFFER_SIZE;
    if (buffer->count < BUFFER_SIZE) {
        buffer->count += 1;
    }
}

float buffer_avg_temp(const SensorBuffer *buffer){ 
    float temp_sum = 0.0;
    float temp_avg = 0.0;

    for (int i = 0; i < BUFFER_SIZE; i++){
        temp_sum += buffer->readings[i].temperature;
    }

    temp_avg = temp_sum / BUFFER_SIZE;
    return temp_avg;

}

float buffer_avg_hum(const SensorBuffer *buffer){ 
    float hum_sum = 0.0;
    float hum_avg = 0.0;

    for (int i = 0; i < BUFFER_SIZE; i++){
        hum_sum += buffer->readings[i].humidity;
    }

    hum_avg = hum_sum / BUFFER_SIZE;
    return hum_avg;

}

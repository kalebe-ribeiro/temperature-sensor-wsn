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

    if (buffer->count == 0) {
        return 0.0; // Avoid division by zero
    }

    for (int i = 0; i < buffer->count; i++){
        temp_sum += buffer->readings[i].temperature;
    }

    temp_avg = temp_sum / buffer->count;
    return temp_avg;

}
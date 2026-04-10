#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#include "sensor.h"
#include "buffer.h"

const int OneWireBus = 4;
OneWire oneWire(OneWireBus);
DallasTemperature sensors(&oneWire);

void setup() {
  sensors.begin();
  Serial.begin(115200);
}

void loop() {
  static SensorBuffer sensorBuffer = {0};
  static SensorData sensorData;
  static unsigned long lastReadTime = millis();

  if (millis() - lastReadTime >= 2000) {
    sensors.requestTemperatures();
    sensorData = read_sensor();
    buffer_push(&sensorBuffer, sensorData);
    lastReadTime = millis();
  }

  if (sensorData.temperature == DEVICE_DISCONNECTED_C) {
    Serial.println("Error: Could not connect to temperature sensor");
    return;
  }
  
  if (sensorData.temperature == 85){
    Serial.println("Error: Temperature reading is invalid");
    return;
  }

  float avg_temp = buffer_avg_temp(&sensorBuffer);

  Serial.print("Temperature:");
  Serial.print(avg_temp);
  Serial.println("°C");

  AlertValues alertValues = sensor_alert(avg_temp);

  if (alertValues.alert_temperature){
    Serial.println("Alert: Temperature is above the threshold!");
  }
}


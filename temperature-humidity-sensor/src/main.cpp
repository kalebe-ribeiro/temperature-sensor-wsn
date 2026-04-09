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

  // VERIFICAR ERRO DE LEITURA DO SENSOR
  if (sensorData.temperature == DEVICE_DISCONNECTED_C) {
    Serial.printf("Error: Could not read temperature data");
    return;
  }

  if (sensorData.temperature == 85){
    Serial.printf("Error: Temperature reading is invalid");
    return;
  }
  

  float avg_temp = buffer_avg_temp(&sensorBuffer);

  Serial.printf("Temperature: %.2f°C",avg_temp);

  AlertValues alertValues = sensor_alert(avg_temp);

  if (alertValues.alert_temperature){
    Serial.printf("Alert: Temperature is above the threshold! %.2f°C\n", sensorData.temperature);
  }
}


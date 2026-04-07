#include <Arduino.h>
#include <DHT.h>
#include "sensor.h"

#define DHTPIN 4
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

SensorData sensorData;
unsigned long lastReadTime = millis();

void setup() {
  dht.begin();
  Serial.begin(9600);
  
}

void loop() {

  if (millis() - lastReadTime >= 2000) {
    sensorData = read_sensor();
    lastReadTime = millis();
  }

  if (isnan(sensorData.humidity) || isnan(sensorData.temperature)){
    Serial.printf("Failed to read from DHT sensor. \n");
    return;
  }
  
  AlertValues alertValues = sensor_alert(sensorData.humidity, sensorData.temperature);

  if (alertValues.alert_humidity){
    Serial.printf("Alert: Humidity is above the threshold! %.2f%%\n", sensorData.humidity);
  }

  if (alertValues.alert_temperature){
    Serial.printf("Alert: Temperature is above the threshold! %.2f°C\n", sensorData.temperature);
  }


}


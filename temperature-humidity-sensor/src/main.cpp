#include <Arduino.h>
#include <DHT.h>
#include "sensor.h"

#define DHTPIN 4
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  dht.begin();
  Serial.begin(9600);
}

void loop() {
  SensorData sensorData;
  sensorData.humidity = dht.readHumidity();
  sensorData.temperature = dht.readTemperature();

  if (isnan(sensorData.humidity) || isnan(sensorData.temperature)){
    Serial.printf("Failed to read from DHT sensor. \n");
    return;
  }
  
  AlertValues AlertValues = sensor_alert(sensorData.humidity, sensorData.temperature);

  if (AlertValues.alert_humidity){
    Serial.printf("Alert: Humidity is above the threshold! %.2f%%\n", sensorData.humidity);
  }
  if (AlertValues.alert_temperature){
    Serial.printf("Alert: Temperature is above the threshold! %.2f°C\n", sensorData.temperature);
  }


  delay(2000);
}


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
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)){
    Serial.printf("Failed to read from DHT sensor. \n");
    return;
  }
  
  sensor_alert(humidity, temperature);

  delay(2000);
}


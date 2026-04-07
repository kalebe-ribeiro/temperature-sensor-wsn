#include <Arduino.h>
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  dht.begin();
  Serial.begin(9600);
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = readTemperature();

  if (isnan(humidity) || isnan(temperature)){
    Serial.println("Failed to read from DHT sensor. ");
    return;

  }
}


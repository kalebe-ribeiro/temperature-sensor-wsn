# temperature-sensor-wsn

This project consists of a temperature wireless sensor network.
Since it's on early stage, I will not cover all of the code in this README.

Components:
ESP32 devkit doit;
Breadboard;
4.7K Ohm resistor (1);
Jumper wires (5);
DS18B20 (waterproof version)

main.cpp:
Main structure of the code, where the logic will integrate the declarations of the header files.
I included the libraries Arduino.h (Arduino framework for esp32), OneWire.h and DallasTemperature.h (needed libraries for DS18B20).
In this early stage I will not describe the full logic within main.cpp since it's a pretty basic structure.

buffer.cpp:
Declared functions related to the buffer, such as buffer_push() and buffer_average().
buffer_push() will require 2 arguments: the buffer where the data read from the sensor will be storaged, and the readings from the sensor, which will be allocated in the buffer.
buffer_avg_temp() will require 1 argument: the buffer itsel, which will then be read to calculate the average temperature.

sensor.cpp:
Declared functions related to the sensor, such as sensor_alert() and read_sensor().
sensor_alert() will read temperature as an argument and return a struct containing booleans in case of high temperature
read_sensor() will read temperature and return in a struct

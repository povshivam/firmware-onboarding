#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "BMEConstants.h"
#include "LEDController.h"

BMEI2CInterface bme;
LEDController led;

bool sensorReady = false;
unsigned long lastSensorRead = 0;

void setup() {
    Serial.begin(BMEConstants::SERIAL_BAUD);

    led.begin();
    sensorReady = bme.begin();

    if (!sensorReady) {
        Serial.println("BME280 failed to initialize");
    }
}

void loop() {
    if (!sensorReady) {
        return;
    }

    unsigned long now = millis();

    if (now - lastSensorRead >= BMEConstants::SENSOR_READ_INTERVAL_MS) {
        lastSensorRead = now;

        bme.update();
        led.setTemperature(bme.getTemperature());

        Serial.print("Temperature: ");
        Serial.print(bme.getTemperature());
        Serial.println(" C");
    }

    led.update();
}
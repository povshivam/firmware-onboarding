#include "LEDController.h"

void LEDController::begin() {
    pinMode(BMEConstants::LED_PIN, OUTPUT);
    digitalWrite(BMEConstants::LED_PIN, LOW);

    ledOn = false;
    lastToggle = millis();
}

void LEDController::setTemperature(float temperature) {
    if (temperature >= BMEConstants::HOT_TEMP_C) {
        blinkInterval = BMEConstants::FAST_BLINK_MS;
    } else if (temperature >= BMEConstants::WARM_TEMP_C) {
        blinkInterval = BMEConstants::MEDIUM_BLINK_MS;
    } else {
        blinkInterval = BMEConstants::SLOW_BLINK_MS;
    }
}

void LEDController::update() {
    unsigned long now = millis();

    if (now - lastToggle >= blinkInterval) {
        lastToggle = now;
        ledOn = !ledOn;

        digitalWrite(BMEConstants::LED_PIN, ledOn ? HIGH : LOW);
    }
}
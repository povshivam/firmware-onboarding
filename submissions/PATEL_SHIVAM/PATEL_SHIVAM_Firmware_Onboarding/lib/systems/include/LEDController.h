#pragma once
#include <Arduino.h>
#include "BMEConstants.h"

class LEDController {
    public:
        void begin();
        void setTemperature(float temperature);
        void update();

    private:
        bool ledOn = false;
        unsigned long lastToggle = 0;
        unsigned long blinkInterval = BMEConstants::SLOW_BLINK_MS;
};
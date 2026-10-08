#pragma once
#include <Adafruit_BME280.h>
#include "BMEConstants.h"

class BMESPIInterface {
    public:
        bool begin();
        void update();
        float getTemperature();

    private:
        Adafruit_BME280 sensor{BMEConstants::SPI_CS_PIN};
        float temperature = 0.0f;
};
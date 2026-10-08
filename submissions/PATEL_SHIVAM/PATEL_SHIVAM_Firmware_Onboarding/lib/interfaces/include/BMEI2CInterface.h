#pragma once
#include <Adafruit_BME280.h>

class BMEI2CInterface {
    public:
        bool begin();
        void update();
        float getTemperature();

    private:
        Adafruit_BME280 sensor;
        float temperature = 0.0f;
};
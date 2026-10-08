#include "BMESPIInterface.h"

bool BMESPIInterface::begin() {
    return sensor.begin();
}

void BMESPIInterface::update() {
    temperature = sensor.readTemperature();
}

float BMESPIInterface::getTemperature() {
    return temperature;
}
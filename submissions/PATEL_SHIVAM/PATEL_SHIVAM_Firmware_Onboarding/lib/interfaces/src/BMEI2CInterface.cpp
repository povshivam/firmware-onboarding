#include "BMEI2CInterface.h"
#include "BMEConstants.h"

bool BMEI2CInterface::begin() {
    return sensor.begin(BMEConstants::I2C_ADDRESS);
}

void BMEI2CInterface::update() {
    temperature = sensor.readTemperature();
}

float BMEI2CInterface::getTemperature() {
    return temperature;
}
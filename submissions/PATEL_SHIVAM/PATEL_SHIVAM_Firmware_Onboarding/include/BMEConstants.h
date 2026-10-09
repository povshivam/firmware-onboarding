#pragma once
#include <Arduino.h>

namespace BMEConstants {
    constexpr unsigned long SERIAL_BAUD = 115200;
    constexpr unsigned long SENSOR_READ_INTERVAL_MS = 500;

    // I2C
    constexpr uint8_t I2C_ADDRESS = 0x76;

    // SPI
    constexpr uint8_t SPI_CS_PIN = 13;

    // LED Controller
    constexpr uint8_t LED_PIN = LED_BUILTIN;
    constexpr float WARM_TEMP_C = 25.0f;
    constexpr float HOT_TEMP_C = 30.0f;

    constexpr unsigned long SLOW_BLINK_MS = 1000;
    constexpr unsigned long MEDIUM_BLINK_MS = 500;
    constexpr unsigned long FAST_BLINK_MS = 100;
}
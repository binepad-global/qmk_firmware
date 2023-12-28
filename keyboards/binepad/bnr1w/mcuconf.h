#pragma once

#include_next <mcuconf.h>

// Need SPI for BLE module
#undef RP_SPI_USE_SPI0
#define RP_SPI_USE_SPI0 TRUE

// Need I2C from the QWICC / STEMA-QT header
// #undef RP_I2C_USE_I2C0
// #define RP_I2C_USE_I2C0 TRUE

// Don't need ADC

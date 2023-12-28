// Copyright 2024 vinorodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#define LEGACY_BLUETOOTH_DRIVER // remove if new driver framework is added

/* RP2040 Specific */
// #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
// #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP23  // ** not actually connected **
// #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

/* Encoder */
#define ENCODER_DEFAULT_POS 0x3 // enable 1:1 resolution

/* Setup SPI */
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP18
#define SPI_MISO_PIN GP20
#define SPI_MOSI_PIN GP19

/* Setup I2C, on STEMA-QT header */
// #define I2C_DRIVER I2CD0
// #define I2C0_SDA_PIN GP12
// #define I2C0_SCL_PIN GP13

/* Bluetooth = Adafruit "Bluefruit" SPI Friend */
#define BLUEFRUIT_LE_CS_PIN GP10 // a.k.a. SPI_SS_PIN
#define BLUEFRUIT_LE_IRQ_PIN GP26
#define BLUEFRUIT_LE_RST_PIN GP4
#define BLUEFRUIT_LE_SCK_DIVISOR 16 // 62.5MHz / 4MHz = 15.625

#ifdef LEGACY_BLUETOOTH_DRIVER
#    define OUTPUT_DEFAULT OUTPUT_BLUETOOTH
#else // LEGACY_BLUETOOTH_DRIVER
#    define SEND_OUTPUT_DEFAULT SEND_OUTPUT_BLUETOOTH
#endif // LEGACY_BLUETOOTH_DRIVER

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

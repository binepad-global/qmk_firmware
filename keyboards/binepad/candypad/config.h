// Copyright 2023 binepad (@binepad)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* ----- Encoder ----- */
#define ENCODER_DEFAULT_POS 0x3  // enable 1:1 resolution


/* ----- I2C (for OLED) ----- */
#define I2C1_SCL_PIN GP23
#define I2C1_SDA_PIN GP22
#define I2C_DRIVER   I2CD1

/* ----- OLED ----- */
#ifdef OLED_DRIVER_ENABLE
    /* configure oled driver for the 128x32 oled */
    #define OLED_DISPLAY_128X32
    #define OLED_TIMEOUT 0
    #define OLED_BRIGHTNESS 128
    #define OLED_UPDATE_INTERVAL 33 // ~30fps

    /* Font */
    #define OLED_FONT_H "glcdfont.c"
    #define OLED_FONT_WIDTH 5
    #define OLED_FONT_HEIGHT 8
#endif

/* ---- Direct pins, for use in `matrix.c` (please read that file) ----- */
#define ____ NO_PIN
// *NB*: DIRECT_PINS_CUSTOM must match the MATRIX_ROWS / MATRIX_COLS matrix structure
#define DIRECT_PINS_CUSTOM { \
    { ____, ____, ____, ____ }, \
    { ____, ____, ____, ____ }, \
    { ____, ____, ____, ____ }, \
    { ____, ____, ____, ____ }, \
    { ____, ____, ____, ____ }, \
    { GP26, GP3,  ____, ____ } }

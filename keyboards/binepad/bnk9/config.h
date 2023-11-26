// Copyright 2023 binepad (@binepad)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define ENCODER_DEFAULT_POS 0x3  // enable 1:1 resolution

#define WS2812_PIO_USE_PIO1
// #define RGB_MATRIX_TIMEOUT 150000  // 2.5 minutes
#define RGB_DISABLE_WHEN_USB_SUSPENDED
#define RGB_MATRIX_LED_PROCESS_LIMIT 9  // All nine keys
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 180  // Not too bright so that the LED's don't burn out

#define ____ NO_PIN
// *NB*: DIRECT_PINS_CUSTOM must match the MATRIX_ROWS / MATRIX_COLS matrix structure
#define DIRECT_PINS_CUSTOM { \
    { ____, ____, ____ }, \
    { ____, ____, ____ }, \
    { ____, ____, ____ }, \
    { GP12, ____, ____ } }

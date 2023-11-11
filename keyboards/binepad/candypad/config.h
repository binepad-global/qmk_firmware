// Copyright 2023 binepad (@binepad)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define ENCODER_DEFAULT_POS 0x3  // enable 1:1 resolution

#define I2C1_SCL_PIN GP23
#define I2C1_SDA_PIN GP22
#define I2C_DRIVER   I2CD1

#define ____ NO_PIN
// *NB*: DIRECT_PINS_2 must match the MATRIX_ROWS / MATRIX_COLS matrix structure
#define DIRECT_PINS_2 { \
    { ____, ____, ____, ____ }, \
    { ____, ____, ____, ____ }, \
    { ____, ____, ____, ____ }, \
    { ____, ____, ____, ____ }, \
    { ____, ____, ____, ____ }, \
    { GP26, GP3,  ____, ____ } }

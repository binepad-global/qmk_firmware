// Copyright 2023 binepad (@binepad)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define ENCODER_DEFAULT_POS 0x3  // enable 1:1 resolution

#define ____ NO_PIN
// *NB*: DIRECT_PINS_2 must match the MATRIX_ROWS / MATRIX_COLS matrix structure
#define DIRECT_PINS_2 { \
    { ____, ____, ____, ____ }, \
    { ____, ____, ____, ____ }, \
    { ____, ____, ____, ____ }, \
    { ____, ____, ____, ____ }, \
    { ____, ____, ____, ____ }, \
    { GP26, GP3,  ____, ____ } }

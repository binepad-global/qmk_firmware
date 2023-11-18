// Copyright 2023 binepad (@binepad)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

#ifndef OLED_SPLASH_TIMEOUT
    #define OLED_SPLASH_TIMEOUT 2500
#endif

enum oled_modes {
    OLED_SPLASH,
    OLED_DEFAULT,
    OLED_OFF,
    _NUM_OLED_MODES
};

// OLED functions
extern uint8_t oled_mode;
extern bool oled_repaint_requested;
extern uint32_t oled_sleep_timer;
extern uint32_t oled_splash_timer;

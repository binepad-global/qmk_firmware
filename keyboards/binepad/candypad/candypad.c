// Copyright 2023 binepad (@binepad)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "candypad.h"

// OLED functions
uint8_t oled_mode = OLED_SPLASH;
bool oled_repaint_requested = false;
uint32_t oled_splash_timer = 0;

#ifdef CONSOLE_ENABLE
void keyboard_post_init_kb(void) {
    // #ifdef CONSOLE_ENABLE
    debug_enable = true;
    // #endif
}
#endif

void housekeeping_task_kb(void) {
    if (0 != oled_splash_timer) {
        if (timer_elapsed(oled_splash_timer) > OLED_SPLASH_TIMEOUT) {
            oled_splash_timer = 0;  // switch off
            oled_repaint_requested = true;
            oled_mode = OLED_DEFAULT;
        }
    }
}

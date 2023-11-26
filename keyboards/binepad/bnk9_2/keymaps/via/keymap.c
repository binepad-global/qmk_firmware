// Copyright 2023 Binepad (@binpad)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_F1, KC_F2, KC_F3,
        KC_F4, KC_F5, KC_F6,
        KC_F7, KC_F8, KC_F9,
        KC_MUTE
    )
};

#if defined(ENCODER_MAP_ENABLE)

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU)
    }
};

#endif

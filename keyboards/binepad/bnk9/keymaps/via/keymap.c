// Copyright 2023 Binepad (@binpad)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_F1, KC_F2, KC_F3,
        KC_F4, KC_F5, KC_F6,
        KC_F7, KC_F8, MO(1),
        KC_MUTE
    ),
    [1] = LAYOUT(
        RGB_HUI,  RGB_SAI, RGB_SPI,
        RGB_HUD,  RGB_SAD, RGB_SPD,
        RGB_RMOD, RGB_MOD, _______,
        RGB_TOG
    )
};

#if defined(ENCODER_MAP_ENABLE)

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) }
};

#endif

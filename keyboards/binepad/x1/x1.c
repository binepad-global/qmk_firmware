/* (c) 2025 Binepad (@binpad) */
/* SPDX-License-Identifier: GPL-2.0-or-later */

#include "x1.h"

void x1_layer_led(uint8_t lyr) {
    gpio_write_pin(IND1_LED, lyr >= 1);
    gpio_write_pin(IND1_LED, lyr >= 2);
    gpio_write_pin(IND1_LED, lyr >= 3);
    gpio_write_pin(IND1_LED, lyr >= 4);
}

void keyboard_pre_init_kb(void) {
    keyboard_pre_init_user();  // Call the user pre-init function if needed

    setPinOutput(IND1_LED); // Set Indicators as output
    writePinLow(IND1_LED); // Set initial indicator low / OFF
    setPinOutput(IND2_LED);
    writePinLow(IND2_LED);
    setPinOutput(IND3_LED);
    writePinLow(IND3_LED);
    setPinOutput(IND4_LED);
    writePinLow(IND4_LED);
}

layer_state_t layer_state_set_kb(layer_state_t state) {
    state = layer_state_set_user(state);
    uint8_t layer = get_highest_layer(state);
    x1_layer_led(layer);
    return state;
}

void matrix_init_kb(void) {
    setPinOutput(COL0_PIN); // Set Col0 as an output
    writePinLow(COL0_PIN); // Set Col0 to low / ground

    matrix_init_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user(keycode, record)) {
        return false;
    }
    switch (keycode) {
        case X1_LAYER_SELECTOR:
            if (record->event.pressed) {
              uint8_t current_layer = get_highest_layer(layer_state);
              uint8_t next_layer = (current_layer + 1) % 5; // Cycle through layers 0-4
              layer_move(next_layer);
              x1_layer_led(next_layer); // Update LED indicators
            }
            return false;

        default:
            return true;
    }
}

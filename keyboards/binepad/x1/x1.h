/* (c) 2025 Binepad (@binpad) */
/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#include "quantum.h"

#define COL0_PIN B8 // Building a 1x2 matrix makes no sense, setting the 1xCol to ground for direct pin access.

#define IND1_LED A3
#define IND2_LED A4
#define IND3_LED A5
#define IND4_LED A6

enum x1_keycodes { X1_LAYER_SELECTOR = QK_KB_1 };

#define X1_LAYER X1_LAYER_SELECTOR

// clang-format off
static inline void x1_led_1_on(void) { gpio_write_pin_high(IND1_LED); }
static inline void x1_led_2_on(void) { gpio_write_pin_high(IND2_LED); }
static inline void x1_led_3_on(void) { gpio_write_pin_high(IND3_LED); }
static inline void x1_led_4_on(void) { gpio_write_pin_high(IND4_LED); }
static inline void x1_led_1_off(void) { gpio_write_pin_low(IND1_LED); }
static inline void x1_led_2_off(void) { gpio_write_pin_low(IND2_LED); }
static inline void x1_led_3_off(void) { gpio_write_pin_low(IND3_LED); }
static inline void x1_led_4_off(void) { gpio_write_pin_low(IND4_LED); }
// clang-format on

void x1_layer_led(uint8_t lyr);

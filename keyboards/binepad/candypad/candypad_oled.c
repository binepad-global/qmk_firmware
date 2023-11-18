// Copyright 2023 binepad (@binepad)
// SPDX-License-Identifier: GPL-2.0-or-later
// Portions of this code are based on [Andrew Kannan](https://github.com/awkannan1)'s
//  work on the Satisfaction75

#include "candypad.h"
#include "oled_driver.h"
#include "keymap_introspection.h"
// #include OLED_FONT_H
#include <stdio.h>  // needed for `snprintf`
#ifdef CONSOLE_ENABLE
    #include "print.h"
    #include "debug.h"
#endif

#ifdef OLED_ENABLE

oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    // oled_set_brightness(128);  // TODO: Make this a saved setting
    oled_mode = OLED_SPLASH;
    oled_splash_timer = sync_timer_read();
    return rotation;
}

static char* get_enc_mode(uint8_t encoder) {

    #ifdef ENCODER_MAP_ENABLE

    static char s_u_d[4] = {24, 38, 25, 0};  // up and down
    static char s_l_r[4] = {27, 38, 26, 0};  // left and right

    uint8_t layer = get_highest_layer(layer_state);
    uint16_t keycode = keycode_at_encodermap_location(layer, encoder, true);  // only reads ENCODER_CW

    switch (keycode) {
        case KC_WH_U:
        case KC_WH_D:
            return "MWL";
            break;

        case KC_VOLD:
        case KC_VOLU:
            return "VOL";
            break;

        case KC_MEDIA_NEXT_TRACK:
        case KC_MEDIA_PREV_TRACK:
            return "MED";
            break;

        case KC_UP:
        case KC_DOWN:
            return (char *)&s_u_d;
            break;

        case KC_LEFT:
        case KC_RIGHT:
            return (char *)&s_l_r;
            break;

        default:
            return "Usr";
            break;
    }

    #else

    return "Err";

    #endif
}

static void __draw_line_h(uint8_t x, uint8_t y, uint8_t len, bool on) {
    for (uint8_t i = 0; i < len; i++) {
        oled_write_pixel(i + x, y, on);
    }
}

static void __draw_line_v(uint8_t x, uint8_t y, uint8_t len, bool on) {
    for (uint8_t i = 0; i < len; i++) {
        oled_write_pixel(x, i + y, on);
    }
}

/* Binepad Logo */
// static void render_binepad_logo(void) {
//     static const unsigned char PROGMEM bp_logo[] = {
//         0,  0,  0,  0,  0,  0,  0,128,192,  0,  0,  0,  0,240,120, 60, 60, 30, 31, 31, 30, 60,124,120,248,240,224,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//         0,  0,  0,  0,  0,  0,255,255,255,192,  0,  0,  0,231,248,248,248,252,252,252,252,248,248,240,  0,  0,  1,  3,255,255,255,255,  0,  0,  0,  0,  6,  6,254,254,206,134,134,198,254,252, 56,  0,  0,  6, 14,254,254,  6,  0,  0,  0,254,254,254, 60,248,224,192,  0,  0,254,254,254,  6,  0,  0,  6,254,254,206,134,134,134,142, 14,  0,  0,  6, 14,254,254,  6,  6,  6,  6,222,252,248,  0,  0,128,224,252, 62, 30,254,248,192,  0,  0,  0,  0,  6,254,254,254,  6,  6,  6,  6, 14, 28,252,248,224,  0,  0,  0,  0,  0,  0,  0,
//         0,  0,  0,  0,  0,  0,255,255,255,255,192,128,  0,  7, 15, 31, 31, 63, 63, 63, 63, 31, 31, 15,  0,  0,128,192,255,255,255,255,  0,  0,  0,  0,  0,  0,127,127,113, 97, 97, 97,115,127, 63, 12,  0, 96,112,127,127, 96,  0,  0, 96,127,127,127,  0,  0,  1,  7, 15, 62,127,127,127,  0,  0,  0,  0,127,127,115, 97, 97, 97, 97,112,112,  0,  0, 64,127,127,  3,  3,  3,  3,  3,  1,  0, 96,124,127, 31, 15, 14, 14, 14, 15, 63,126,112, 96,  0,  0,127,127,127, 96, 96, 96, 96,112, 56, 63, 31,  7,  0,  0,  0,  0,  0,  0,  0,
//         0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7,  7, 15, 31, 30, 62, 60,120,248,248,120, 60, 62, 30, 31, 15,  7,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//     };
//     oled_write_raw_P((char *)bp_logo, sizeof(bp_logo));
// }

/* CandyKeys Logo */
// static void render_candykeys_logo(void) {
//     static const unsigned char PROGMEM ck_logo[] = {
//         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,224,240,248,252,254,254,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,128,192,224,240,248,252,254,255,255,255,255,255,127, 63, 31, 15,  7,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,255,255,255,255,255,255,255,255,  1,  1,  1,129,225,225,241, 49,241,225,193,  1,  1,  1,  1,255,255,255,255,255,127, 63, 31, 15,  7,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,255,255,255,255,255,255,255,255,128,128,128,129,135,143,143,140,143,135,131,128,128,128,128,255,255,255,255,255,254,252,248,240,224,192,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  7, 15, 31, 63,127,127,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,  1,  3,  7, 15, 31, 63,127,255,255,255,255,255,254,252,248,240,224,192,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//     };
//     oled_write_raw_P((char *)ck_logo, sizeof(ck_logo));
// }

/* Collaboration logos */
static void render_colab_logo(void) {
    static const unsigned char PROGMEM cl_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,192,  0,  0,  0,  0,240,120, 60, 60, 30, 31, 31, 30, 60,124,120,248,240,224,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,224,240,248,248,252,252,252,254,254,254,254,254,254,254,254,254,254,254,254,254,  0,  0,128,192,224,240,248,252,254,254,254,254,126, 62, 30, 14,  6,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,255,255,192,  0,  0,  0,231,248,248,248,252,252,252,252,248,248,240,  0,  0,  1,  3,255,255,255,255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 16, 32, 64,128,  0,128, 64, 32, 16,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,254,255,255,255,255,255,255,  1,  1,  1,129,193,225,113, 49,113,225,193,129,  1,  1,  1,254,255,255,255,127, 63, 31, 15,  7,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,255,255,255,192,128,  0,  7, 15, 31, 31, 63, 63, 63, 63, 31, 31, 15,  0,  0,128,192,255,255,255,255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 16,  8,  4,  2,  1,  2,  4,  8, 16,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,127,255,255,255,255,255,255,128,128,128,129,131,135,142,140,142,135,131,129,128,128,128,127,255,255,255,254,252,248,240,224,192,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7,  7, 15, 31, 30, 62, 60,120,248,248,120, 60, 62, 30, 31, 15,  7,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  7, 15, 31, 31, 63, 63, 63,127,127,127,127,127,127,127,127,127,127,127,127,127,  0,  0,  1,  3,  7, 15, 31, 63,127,127,127,127,126,124,120,112, 96, 64,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    };
    oled_write_raw_P((char *)cl_logo, sizeof(cl_logo));
}

void draw_default(void) {
    bool on;

    // --- Show Layer ---

    oled_set_cursor(0, 1);
    oled_write_P(PSTR("LAYER"), false);

    oled_set_cursor(6, 1);
    oled_write_char(get_highest_layer(layer_state) + 0x30, true);

    __draw_line_h((OLED_FONT_WIDTH*6)-1, OLED_FONT_HEIGHT-1, OLED_FONT_WIDTH+1, true);
    __draw_line_v((OLED_FONT_WIDTH*6)-1, OLED_FONT_HEIGHT, OLED_FONT_HEIGHT, true);


    // --- Show Encoder 1 ---

    oled_set_cursor(13, 1);
    oled_write_P(PSTR("ENC1"), false);

    oled_set_cursor(18, 1);
    oled_write(get_enc_mode(0), true);

    __draw_line_h((OLED_FONT_WIDTH*18)-1, OLED_FONT_HEIGHT-1, (OLED_FONT_WIDTH*3)+1, true);
    __draw_line_v((OLED_FONT_WIDTH*18)-1, OLED_FONT_HEIGHT, OLED_FONT_HEIGHT, true);


    // --- Show Encoder 2 ---

    oled_set_cursor(13, 3);
    oled_write_P(PSTR("ENC2"), false);

    oled_set_cursor(18, 3);
    oled_write(get_enc_mode(1), true);

    __draw_line_h((OLED_FONT_WIDTH*18)-1, (OLED_FONT_HEIGHT*3)-1, (OLED_FONT_WIDTH*3)+1, true);
    __draw_line_v((OLED_FONT_WIDTH*18)-1, OLED_FONT_HEIGHT*3, OLED_FONT_HEIGHT, true);

    // --- Keyboard Modifiers ---

    led_t led_state = host_keyboard_led_state();
    oled_set_cursor(4, 3);
    if (led_state.caps_lock && !led_state.num_lock) {  // Caps-Lock transcends keyboards, so show it if on if num-lock is off
        oled_write_P(PSTR("CAP"), true );
    } else {
        oled_write_P(PSTR("NUM"), led_state.num_lock );
    }
    on = led_state.num_lock || led_state.caps_lock;
    __draw_line_h((OLED_FONT_WIDTH*4)-1, (OLED_FONT_HEIGHT*3)-1, (OLED_FONT_WIDTH*3)+1, on);
    __draw_line_v((OLED_FONT_WIDTH*4)-1, OLED_FONT_HEIGHT*3, OLED_FONT_HEIGHT, on);

    // --- Show keymap matrix ---

    #define MXDS_X 2
    #define MXDS_Y (OLED_FONT_HEIGHT * 3)

    // matrix
    for (uint8_t x = 0; x < MATRIX_ROWS-1; x++) {
        for (uint8_t y = 0; y < MATRIX_COLS; y++) {
            on = (matrix_get_row(x) & (1 << y)) > 0;
            oled_write_pixel(MXDS_X + y, MXDS_Y + x + 1, on);
        }
    }

    on = (matrix_get_row(1) & (1 << 3)) > 0;  // `+`
    oled_write_pixel(MXDS_X + 3, MXDS_Y + 1 + 2, on);

    on = (matrix_get_row(3) & (1 << 3)) > 0;  // `Enter`
    oled_write_pixel(MXDS_X + 3, MXDS_Y + 3 + 2, on);

    on = (matrix_get_row(4) & (1 << 0)) > 0;  // `0`
    oled_write_pixel(MXDS_X + 0 + 1, MXDS_Y + 4 + 1, on);

    on = (matrix_get_row(5) & (1 << 0)) > 0;  // Enc 1 press
    oled_write_pixel(MXDS_X + 2, MXDS_Y, on);

    on = (matrix_get_row(5) & (1 << 1)) > 0;  // Enc 2 press
    oled_write_pixel(MXDS_X + 3, MXDS_Y, on);

    // outline
    __draw_line_h(MXDS_X-2, MXDS_Y-2, 8, true);
    __draw_line_h(MXDS_X-2, MXDS_Y+7, 8, true);
    __draw_line_v(MXDS_X-2, MXDS_Y-1, 8, true);
    __draw_line_v(MXDS_X+5, MXDS_Y-1, 8, true);
}

bool oled_task_kb(void) {
    if (!oled_task_user()) { return false; }
    // if (!oled_task_needs_to_repaint()) { return false; }

    /* !!! oled_clear(); // is broken !!! */
    if (oled_repaint_requested) {
        oled_repaint_requested = false;
        oled_clear();
        return false;
    }

    switch (oled_mode) {
        case OLED_SPLASH:
            render_colab_logo();
            break;

        case OLED_DEFAULT:
        default:
            draw_default();
            break;
    }

    return false;
}

#endif  // OLED_ENABLE

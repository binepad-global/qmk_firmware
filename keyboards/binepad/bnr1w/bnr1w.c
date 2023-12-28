
#include "bluefruit_le_spi.h"

/* ----- LEGACY BLUETOOTH DRIVER ----- */

// clang-format off
void bluetooth_init(void) { bluefruit_le_init(); }
void bluetooth_task(void) { bluefruit_le_task(); }
void bluetooth_send_keyboard(report_keyboard_t *report) { bluefruit_le_send_keyboard(report); }
void bluetooth_send_mouse(report_mouse_t *report) { bluefruit_le_send_mouse(report); }
void bluetooth_send_consumer(uint16_t usage) { bluefruit_le_send_consumer(usage); }
// clang-format on

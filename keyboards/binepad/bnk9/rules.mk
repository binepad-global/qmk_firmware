# @see `info.json` for config

BOARD = GENERIC_RP_RP2040
CUSTOM_MATRIX = yes
RGB_MATRIX_CUSTOM_KB = yes
SRC += matrix.c \
       bkn9_via.c

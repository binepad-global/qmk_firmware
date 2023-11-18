# @see `info.json` for config

CUSTOM_MATRIX = yes
SRC += matrix.c \
       candypad_oled.c

OPT_DEFS += -DHAL_USE_I2C=TRUE

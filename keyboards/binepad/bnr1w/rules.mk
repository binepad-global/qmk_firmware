# @see `info.json` for config

BOARD = GENERIC_RP_RP2040
NKRO_ENABLE = no  # must not use NKRO in Bluetooth

# Custom bluetooth driver
# BLUETOOTH_ENABLE = yes  # -> info.json
# BLUETOOTH_DRIVER = custom  # -> info.json
# SPI_DRIVER_REQUIRED = yes
SPI_DRIVER_REQUIRED = yes
SRC += bluefruit_le_spi.cpp

# CONSOLE_ENABLE = yes  # -> info.json

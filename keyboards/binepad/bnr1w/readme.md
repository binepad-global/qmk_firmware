# BINEPAD BNR1W

![BINEPAD BNK9-2](https://placehold.co/600x400/FFF/EA5823?text=BINEPAD+BNR1W)

*The BNR1W is a multifunction wireless (bluetooth) knob, which can be rotated, pressed, and rotated while pressed.*

* Keyboard Maintainer: [vinorodrigues](https://github.com/vinorodrigues)
* Hardware Supported: **BNR1W** *(ft. RP2040 MCU and Adafruit "Bluefruit" technology)*
* Hardware Availability: [binepad.com](https://www.binepad.com/product-page/bnr1w)

Make example for this keyboard (after setting up your build environment):

    make binepad/bnr1w:default

Flashing example for this keyboard:

    make binepad/bnr1w:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down *(press and hold down)* the key knob and plug in the keyboard's USB cable.
* **Keycode in layout**: Press the key mapped to `QK_BOOT` (or `RESET`) if it is available

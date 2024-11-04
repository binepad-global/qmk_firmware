# binepad/bnk8

<!-- TODO: Load marketing image to Imgur -->
![BINEPAD BNK8](https://placehold.co/640x240/FFF/EA5823?text=BINEPAD++BNK8)

A compact 8-key 3x3 macropad with a rotary encoder at the top right.

* Keyboard Maintainer: [binepad](https://github.com/binepad)
* Hardware Supported: BINPAD BNK8
* Hardware Availability: [binepad.com](https://www.binepad.com/product-page/bnk8)

Make example for this keyboard (after setting up your build environment):

    make binepad/bnk8:default

Flashing example for this keyboard:

    make binepad/bnk8:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key) and plug in the keyboard
<!-- TODO: Check if KB has a physical reset -->
<!-- * **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead -->
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available

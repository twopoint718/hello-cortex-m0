# hello-cortex-m0

Source code for programming the [hawk dev board](https://github.com/MalphasWats/hawk).

This is a small breakout board with 4-6V voltage regulator (so you can power it using a wider range of voltages), an on-board LED, and... well that's about it.
It's based on a [Microchip ATSAMD10C14A microcontroller](https://www.microchip.com/wwwproducts/en/ATSAMD10C14).
This is an [Arm Cortex-M0](https://developer.arm.com/ip-products/processors/cortex-m/cortex-m0) in a 14-pin [SOIC](https://en.m.wikipedia.org/wiki/Small_Outline_Integrated_Circuit) package.

## Setup, Requirements, and Building

1. Install the ARM GCC compiler and associated toolchain directly from Arm's Developer page:
   [GNU Arm Embedded Toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads)
   This is a [cross compiler](https://en.wikipedia.org/wiki/Cross_compiler) that _runs_ on your desktop platform, but produces executables for a _target_.
   In this case of this compiler, Arm Cortex-M/R series.
2. You should have at least the following programs in your `PATH`:
   * `arm-none-eabi-gcc` (compiler)
   * `arm-none-eabi-ld` (linker)
   * `arm-none-eabi-as` (assembler)
   * `arm-none-eabi-objcopy` (object-copier 😜)
3. Compile and create a [hex](https://en.wikipedia.org/wiki/Intel_HEX) file using `make`:

       make
4. Install the [J-Link Software and Documentation Pack](https://www.segger.com/downloads/jlink/#J-LinkSoftwareAndDocumentationPack)
5. Upload the code to the dev board using the [J-Link](https://www.segger.com/products/debug-probes/j-link/) (or another debug probe).
   If using a J-Link, you can use the provided script, `upload_firmware.sh`, to upload the firmware:

       make flash
6. ℹ️ _Optional:_ You may also start the `JLinkGDBServer`, which came with the J-Link download.
   You may then connect to the board and do all the usual debugging things that you are used to.
   How exactly this is set up will vary a lot by editor & environment.

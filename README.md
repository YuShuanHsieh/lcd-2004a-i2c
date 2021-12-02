# Sample code for LCD 2004 via I2C

This is a sample code for displaying characters on LCD 2004A device via I2C protocol. This code is based on example code from [pico-examples/lcd_1602_i2c](https://github.com/raspberrypi/pico-examples/tree/master/i2c/lcd_1602_i2c) and make some changes including:
1. Separating the example code into different source files to make it more clear.
2. Add `struct lcd_device` so that we can use different I2C pins instead of default one.
3. Check LCD's I2C address is available before initializing it.
4.  Fix invalid memory access issues during displaying messages.

The reason why I create this repo is there are lots of sample code for LCD 1602 or 2004 device, but few of them describe how the sample code works. I will try to add some information to help user to understand the process of sample code.

## Dependencies
- pico SDK
- CMake

## Datasheet
1. [LCD 2004A datasheet](https://cdn-shop.adafruit.com/datasheets/TC2004A-01.pdf)
2. [I2C remote 8-bit I/O expander datasheet](https://www.nxp.com/docs/en/data-sheet/PCF8574_PCF8574A.pdf)

## Build
1. Setup `PICO_SDK_PATH` environment variable
```bash
export PICO_SDK_PATH=~/pico/pico-sdk
```
2. Create a `build` folder
```bash
mkdir build && cd build
```
3. In build directory, run CMake to configure the project
```bash
# or cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake ..
```
4. Build an executable file
```bash
make
```
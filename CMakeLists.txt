cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(lcd_2004_i2c C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

add_executable(lcd_2004_i2c
        main.c lcd_2004_i2c.c lcd_2004_i2c.h
        )
target_link_libraries(lcd_2004_i2c pico_stdlib hardware_i2c)

pico_add_extra_outputs(lcd_2004_i2c)
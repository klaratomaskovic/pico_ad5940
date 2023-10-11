cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(AD5940_SPI C CXX ASM)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

pico_sdk_init()

add_executable(AD5940_SPI)
target_sources(AD5940_SPI PRIVATE main.c AD5940_SPI.c)

pico_enable_stdio_usb(AD5940_SPI 1)

pico_add_extra_outputs(AD5940_SPI)


include(../../ad5940lib-rp2040.cmake)

target_link_libraries(AD5940_SPI 
pico_stdlib
ad5940lib-rp2040
)

cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)



project(AD5940_IMPEDANCE C CXX ASM)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

pico_sdk_init()

add_executable(AD5940_IMPEDANCE)
target_sources(AD5940_IMPEDANCE PRIVATE main.c AD5940Main.c Impedance.c)

pico_enable_stdio_usb(AD5940_IMPEDANCE 1)

pico_add_extra_outputs(AD5940_IMPEDANCE)


include(../../ad5940lib-rp2040.cmake)

target_link_libraries(AD5940_IMPEDANCE 
pico_stdlib
ad5940lib-rp2040
)

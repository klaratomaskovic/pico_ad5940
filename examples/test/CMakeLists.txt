cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)



project(test C CXX ASM)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

pico_sdk_init()

add_executable(test)
target_sources(test PRIVATE test.c AD5940_SPI.c)

pico_enable_stdio_usb(test 1)

pico_add_extra_outputs(test)


include(../../ad5940lib-rp2040.cmake)

target_link_libraries(test 
pico_stdlib
ad5940lib-rp2040
)

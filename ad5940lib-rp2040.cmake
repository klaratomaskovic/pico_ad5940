
cmake_minimum_required(VERSION 3.12)

add_library(ad5940lib-rp2040 INTERFACE)

target_include_directories(ad5940lib-rp2040 INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/src
    ${CMAKE_CURRENT_LIST_DIR}/ad5940lib
)

target_sources(ad5940lib-rp2040 INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/src/ad5940lib-rp2040.c
    ${CMAKE_CURRENT_LIST_DIR}/ad5940lib/ad5940.c

    )

if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/../../src/pinout.h)
    target_include_directories(ad5940lib-rp2040 INTERFACE ${CMAKE_CURRENT_LIST_DIR}/../../src)
    #target_sources(ad5940lib-rp2040 INTERFACE ${CMAKE_CURRENT_LIST_DIR}../../src/pinout.h)
endif()


target_link_libraries(ad5940lib-rp2040 INTERFACE
    pico_stdlib
    hardware_spi
)



add_compile_definitions(CHIPSEL_594X)
#include "ad5940.h"

//Create a pinout.h File for your custom design
#if __has_include("pinout.h")
    #include "pinout.h"
#endif

//Use dafault hardware definitions if no custom definitions are found
#if !defined(AD5940_SPI_INSTANCE) || !defined(AD5940_SPI_SCK_PIN) || !defined(AD5940_SPI_MOSI_PIN) || !defined(AD5940_SPI_MISO_PIN) || !defined(AD5940_SPI_CS_PIN) || !defined(AD5940_RST_PIN) || !defined(AD5940_INT_PIN)
    #warning Not all required pins are defined. Using pico defaults for missing definitions.
    #ifndef AD5940_SPI_INSTANCE
        #define AD5940_SPI_INSTANCE PICO_DEFAULT_SPI_INSTANCE
    #endif
    #ifndef AD5940_SPI_SCK_PIN
        #define AD5940_SPI_SCK_PIN PICO_DEFAULT_SPI_SCK_PIN
    #endif
    #ifndef AD5940_SPI_MOSI_PIN
        #define AD5940_SPI_MOSI_PIN PICO_DEFAULT_SPI_TX_PIN
    #endif
    #ifndef AD5940_SPI_MISO_PIN
        #define AD5940_SPI_MISO_PIN PICO_DEFAULT_SPI_RX_PIN
    #endif
    #ifndef AD5940_SPI_CS_PIN
        #define AD5940_SPI_CS_PIN PICO_DEFAULT_SPI_CSN_PIN
    #endif
    #ifndef AD5940_RST_PIN
        #define AD5940_RST_PIN 20
    #endif
    #ifndef AD5940_INT_PIN
        #define AD5940_INT_PIN 21
    #endif
    
#endif

#ifndef AD5940_SPI_SPEED
        #define AD5940_SPI_SPEED (10 * 1000 * 1000) //10MBd Should do it
#endif

void IntCallback(unsigned int gpio, unsigned long event_mask);
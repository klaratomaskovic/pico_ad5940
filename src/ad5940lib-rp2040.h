#ifndef ad5940lib_rp2040_h
#define ad5940lib_rp2040_h

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

inline void AD5940_ReadWriteNBytes(unsigned char *pSendBuffer,unsigned char *pRecvBuff,unsigned long length);

inline void AD5940_CsClr(void);

inline void AD5940_CsSet(void);

inline void AD5940_RstSet(void);

inline void AD5940_RstClr(void);

inline void AD5940_Delay10us(uint32_t time);

inline uint32_t AD5940_GetMCUIntFlag(void);

inline uint32_t AD5940_ClrMCUIntFlag(void);

uint32_t AD5940_MCUResourceInit(void *pCfg, void* userCallback);




#endif
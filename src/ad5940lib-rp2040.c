#include "ad5940lib-rp2040.h"
#include "ad5940.h"
#include "pico/stdlib.h"
#include "hardware/spi.h"

#if !defined(AD5940_SPI_INSTANCE) || !defined(AD5940_SPI_SCK_PIN) || !defined(PAD5940_SPI_MOSI_PIN) || !defined(AD5940_SPI_MISO_PIN) || !defined(AD5940_SPI_CS_PIN) || !defined(AD5940_RST_PIN) || !defined(AD5940_SPI_SPEED)
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
    #ifndef AD5940_SPI_SPEED
        #define AD5940_SPI_SPEED (10 * 1000 * 1000) //10MBd Should do it
    #endif
#endif

void AD5940_ReadWriteNBytes(unsigned char *pSendBuffer,unsigned char *pRecvBuff,unsigned long length)
{
  spi_write_read_blocking(AD5940_SPI_INSTANCE, pSendBuffer, pRecvBuff, length);
}

void AD5940_CsClr(void)
{
    sleep_us(1); //This is dependant on SPI Clock Speed!
    gpio_put(AD5940_SPI_CS_PIN, 0);
    //sleep_us(1); //Aftersleep is apparently not needed

}

void AD5940_CsSet(void)
{   
    gpio_put(AD5940_SPI_CS_PIN, 1);
    
}

void AD5940_RstSet(void)
{
    gpio_put(AD5940_RST_PIN, 1);
}

void AD5940_RstClr(void)
{
    gpio_put(AD5940_RST_PIN, 0);
}

void AD5940_Delay10us(uint32_t time)
{
  sleep_us(10*time);
}

uint32_t AD5940_GetMCUIntFlag(void)
{
}

uint32_t AD5940_ClrMCUIntFlag(void)
{
}

/* Functions that used to initialize MCU platform */

uint32_t AD5940_MCUResourceInit(void *pCfg)
{
    spi_init(AD5940_SPI_INSTANCE, AD5940_SPI_SPEED);
    spi_set_format(AD5940_SPI_INSTANCE, 8, 0, 0, SPI_MSB_FIRST);
    gpio_set_function(AD5940_SPI_SCK_PIN, GPIO_FUNC_SPI);
    gpio_set_function(AD5940_SPI_MOSI_PIN, GPIO_FUNC_SPI);
    gpio_set_function(AD5940_SPI_MISO_PIN, GPIO_FUNC_SPI);

    gpio_init(AD5940_SPI_CS_PIN);
    gpio_set_dir(AD5940_SPI_CS_PIN, GPIO_OUT);

    gpio_init(AD5940_RST_PIN);
    gpio_set_dir(AD5940_RST_PIN, GPIO_OUT);
    gpio_pull_up(AD5940_RST_PIN);
  
    AD5940_CsSet();
    AD5940_RstSet();
    return 0;
}

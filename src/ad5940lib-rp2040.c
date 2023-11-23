#include "ad5940lib-rp2040.h"
#include "pico/stdlib.h"
#include "hardware/spi.h"

bool IntFlag = 0;

void (*userCallback)(void) = NULL;

void IntCallback(unsigned int gpio, unsigned long event_mask){
    IntFlag = 1;
    if (userCallback != NULL){
        userCallback();
    }
}

inline void AD5940_ReadWriteNBytes(unsigned char *pSendBuffer,unsigned char *pRecvBuff,unsigned long length)
{
  spi_write_read_blocking(AD5940_SPI_INSTANCE, pSendBuffer, pRecvBuff, length);
}

inline void AD5940_CsClr(void)
{
    sleep_us(1); //This is dependant on SPI Clock Speed!
    gpio_put(AD5940_SPI_CS_PIN, 0);
    //sleep_us(1); //Aftersleep is apparently not needed

}

inline void AD5940_CsSet(void)
{   
    gpio_put(AD5940_SPI_CS_PIN, 1);
    
}

inline void AD5940_RstSet(void)
{
    gpio_put(AD5940_RST_PIN, 1);
}

inline void AD5940_RstClr(void)
{
    gpio_put(AD5940_RST_PIN, 0);
}

inline void AD5940_Delay10us(uint32_t time)
{
  sleep_us(10*time);
}

inline uint32_t AD5940_GetMCUIntFlag(void)
{
    return IntFlag;
}

inline uint32_t AD5940_ClrMCUIntFlag(void)
{
    IntFlag = 0;
}


//Initalize the RP2040 for connection to the AD5940
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

    gpio_init(AD5940_INT_PIN);
    gpio_set_dir(AD5940_INT_PIN, GPIO_IN);
    gpio_set_irq_enabled_with_callback(AD5940_INT_PIN, GPIO_IRQ_EDGE_FALL, true, &IntCallback);
  
    AD5940_CsSet();
    AD5940_RstSet();
    return 0;
}

void AD5940_SetUserCallback(void* callback)
{
    userCallback = callback;
}




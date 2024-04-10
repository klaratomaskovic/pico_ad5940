/*
#define AD5940_SPI_INSTANCE spi1
#define AD5940_SPI_SCK_PIN 26
#define AD5940_SPI_MOSI_PIN 27
#define AD5940_SPI_MISO_PIN 28
#define AD5940_SPI_CS_PIN 29
#define AD5940_RST_PIN 22
#define AD5940_INT_PIN 17
*/



#include <stdio.h>
#include "pico/stdlib.h"
#include "ad5940lib-rp2040.h"

const uint LED_PIN = 2;
unsigned long temp;

int write_mux(char out);


int main()
{

    stdio_init_all();
    sleep_ms(1000);
    printf("Starting AD5940 Code");
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN, 1);


    AD5940_MCUResourceInit(NULL);

    sleep_ms(2000);

    AD5940_Main();
    
    gpio_put(LED_PIN, 0);
    
    return 0;
}

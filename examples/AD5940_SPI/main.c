#define AD5940_SPI_INSTANCE spi1
#define AD5940_SPI_SCK_PIN 26
#define AD5940_SPI_MOSI_PIN 27
#define AD5940_SPI_MISO_PIN 28
#define AD5940_SPI_CS_PIN 29
#define AD5940_RST_PIN 22
#define AD5940_INT_PIN 17

#define MUX_SER 23
#define MUX_SRCLK 24
#define MUX_RCLK 25

#define AD5940_SPI_SPEED (10 * 1000)

#include <stdio.h>
#include "pico/stdlib.h"
#include "ad5940lib-rp2040.h"

const uint LED_PIN = 8;
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

    // Init shift register pins
    gpio_init(MUX_SER);
    gpio_init(MUX_SRCLK);
    gpio_init(MUX_RCLK);
    gpio_set_dir(MUX_SER, GPIO_OUT);
    gpio_set_dir(MUX_SRCLK, GPIO_OUT);
    gpio_set_dir(MUX_RCLK, GPIO_OUT);
    gpio_put(MUX_SER, 0);
    gpio_put(MUX_SRCLK, 0);
    gpio_put(MUX_RCLK, 0);

    write_mux((char)0b11100000);

    //AD5940_MCUResourceInit(NULL);

    sleep_ms(2000);

    //AD5940_Main();
    
    gpio_put(LED_PIN, 0);
    
    return 0;
}

int write_mux(char out)
{
    for (int i = 0; i < 8; ++i)
    {
        gpio_put(MUX_SER, (out>>i)&0x01);
        sleep_ms(1);
        gpio_put(MUX_SRCLK, 1);
        sleep_ms(1);
        gpio_put(MUX_SRCLK, 0);

    }
    gpio_put(MUX_SER, 0);

    gpio_put(MUX_RCLK, 1);
    sleep_ms(1);
    gpio_put(MUX_RCLK, 0);

    return 0;

}
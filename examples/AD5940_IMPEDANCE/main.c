#include <stdio.h>
#include "pico/stdlib.h"
#include "ad5940lib-rp2040.h"
#include "Impedance.h"

#define MUX_SER 23
#define MUX_SRCLK 24
#define MUX_RCLK 25

#define GUARD_EN 14


const uint LED_PIN = 9;
unsigned long temp;

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

int main() {
    

    stdio_init_all();
    sleep_ms(1000);
    printf("Starting AD5940 Code");
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN, 1);


    gpio_init(GUARD_EN);
    gpio_set_dir(GUARD_EN, GPIO_OUT);
    gpio_put(GUARD_EN, 0);

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

    write_mux((char)0b00001011);

    AD5940_MCUResourceInit(NULL);
    

    sleep_ms(2000);

    AD5940_Main();

    return 0;
}
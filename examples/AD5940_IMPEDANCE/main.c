#include <stdio.h>
#include "pico/stdlib.h"
#include "ad5940lib-rp2040.h"
#include "Impedance.h"

#define MUX_SER 23
#define MUX_SRCLK 24
#define MUX_RCLK 25

#define GUARD_EN 14


#define LED_PIN 2

unsigned long temp;

int main() {
    

    stdio_init_all();
    sleep_ms(1000);
    printf("Starting AD5940 Code\n");
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN, 1);

    AD5940_MCUResourceInit(NULL);

    sleep_ms(2000);

    printf("Inited MCU\n");


    AD5940_Main();

    return 0;
}
#include <stdio.h>
#include "pico/stdlib.h"
#include "ad5940lib-rp2040.h"

const uint LED_PIN = 2;
unsigned long temp;

int main() {
    

    stdio_init_all();
    sleep_ms(1000);
    printf("Starting AD5940 Code");
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN, 1);

    AD5940_MCUResourceInit(NULL);
    

    sleep_ms(2000);

    AD5940_Main();

    while(true){
        temp = AD5940_ReadReg(REG_AFECON_ADIID);
        printf("Read ADIID register, got: 0x%04lx\n", temp);
        sleep_ms(100);
    }



    return 0;
}
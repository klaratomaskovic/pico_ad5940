#ifndef PINOUT_H
#define PINOUT_H

#define AD5940_SPI_INSTANCE spi0 
#define AD5940_SPI_SCK_PIN 18 //P3 Pin 6 Arduino D13
#define AD5940_SPI_MOSI_PIN 19 //P3 Pin 4 Arduino D11
#define AD5940_SPI_MISO_PIN 16 //P3 Pin 5 Arduino D12
#define AD5940_SPI_CS_PIN 17 //P3 Pin 3 Arduino D10
#define AD5940_RST_PIN 20 //P1 Pin 4 
#define AD5940_INT_PIN 21

#define AD5940_SPI_SPEED (10 * 1000) //10MBd Should do it

#endif /* PINOUT_H */
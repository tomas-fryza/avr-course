/* 
 * Read values from I2C (TWI) temperature/humidity sensor and send
 * them to OLED screen.
 * (c) 2023-2024 Tomas Fryza, MIT license
 *
 * Developed using PlatformIO and AVR 8-bit Toolchain 3.6.2.
 * Tested on Arduino Uno board and ATmega328P, 16 MHz.
 */

// -- Includes -------------------------------------------------------
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include <twi.h>            // I2C/TWI library for AVR-GCC
#include <oled.h>
#include <stdlib.h>         // C library. Needed for number conversions


// -- Defines --------------------------------------------------------
#define DHT_ADR 0x5c
#define DHT_HUM_MEM 0
#define DHT_TEMP_MEM 2


// -- Global variables -----------------------------------------------
volatile uint8_t update_oled = 0;
volatile uint8_t dht12_values[5];


// -- Function definitions -------------------------------------------
/*
 * Function: Main function where the program execution begins
 * Purpose:  Wait for new data from the sensor and sent them to OLED.
 * Returns:  none
 */
int main(void)
{
    char string[2];  // String for converting numbers by itoa()

    twi_init();

    // Init OLED
    oled_init(OLED_DISP_ON);
    oled_clrscr();

    oled_charMode(DOUBLESIZE);
    oled_puts("OLED disp.");

    oled_charMode(NORMALSIZE);

    oled_gotoxy(0, 2);
    oled_puts("128x64, SH1106");

    // oled_drawLine(x1, y1, x2, y2, color)
    oled_drawLine(0, 25, 120, 25, WHITE);

    oled_gotoxy(0, 4);
    oled_puts("AVR course, Brno");

    oled_gotoxy(0, 6);
    oled_puts("Temperature [C]:");
    oled_gotoxy(0, 7);
    oled_puts("Humidity    [\%]:");

    // Copy buffer to display RAM
    oled_display();

    // Timer1
    TIM1_ovf_1sec();
    TIM1_ovf_enable();

    sei();

    // Infinite loop
    while (1)
    {
        if (update_oled == 1)
        {
            // Clear previous temperature value on OLED
            oled_gotoxy(17, 6);
            oled_puts("    ");

            // Display new temperature data
            oled_gotoxy(17, 6);
            itoa(dht12_values[2], string, 10);
            oled_puts(string);
            oled_puts(".");
            itoa(dht12_values[3], string, 10);
            oled_puts(string);

            // Clear previous humidity values on OLED
            oled_gotoxy(17, 7);
            oled_puts("    ");

            // Display new humidity data
            oled_gotoxy(17, 7);
            itoa(dht12_values[0], string, 10);
            oled_puts(string);
            oled_puts(".");
            itoa(dht12_values[1], string, 10);
            oled_puts(string);

            oled_display();

            // Do not print it again and wait for the new data
            update_oled = 0;
        }
    }

    // Will never reach this
    return 0;
}


// -- Interrupt service routines -------------------------------------
/*
 * Function: Timer/Counter1 overflow interrupt
 * Purpose:  Read temperature and humidity from DHT12, SLA = 0x5c.
 */
ISR(TIMER1_OVF_vect)
{
    static uint8_t n_ovfs = 0;

    n_ovfs++;
    // Read the data every 5 secs
    if (n_ovfs >= 5)
    {
        n_ovfs = 0;

        // Test ACK from Temp/Humid sensor
        twi_start();
        if (twi_write((DHT_ADR<<1) | TWI_WRITE) == 0) {
            // Set internal memory location
            twi_write(DHT_HUM_MEM);
            twi_stop();
            // Read data from internal memory
            twi_start();
            twi_write((DHT_ADR<<1) | TWI_READ);
            dht12_values[0] = twi_read(TWI_ACK);
            dht12_values[1] = twi_read(TWI_ACK);
            dht12_values[2] = twi_read(TWI_ACK);
            dht12_values[3] = twi_read(TWI_NACK);

            update_oled = 1;
        }
        twi_stop();
    }
}

/***********************************************************************
 * 
 * Alternately toggle two LEDs with the push button.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2018-2020 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/

/* Defines -----------------------------------------------------------*/
#define LED_GREEN   PB5     // AVR pin where green LED is connected
#define BLINK_DELAY 250
#ifndef F_CPU
#define F_CPU 16000000      // CPU frequency in Hz required for delay
#endif

/* Includes ----------------------------------------------------------*/
#include <util/delay.h>     // Functions for busy-wait delay loops
#include <avr/io.h>         // AVR device-specific IO definitions

/* Functions ---------------------------------------------------------*/
/**
 * Main function where the program execution begins. Toggle two LEDs 
 * with the push button.
 */
int main(void)
{
    /* GREEN LED */
    // Set pin as output in Data Direction Register...
    DDRB = DDRB | (1<<LED_GREEN);
    // ...and turn LED off in Data Register
    PORTB = PORTB & ~(1<<LED_GREEN);

    /* second LED */
    // WRITE YOUR CODE HERE

    // Infinite loop
    while (1)
    {
        // Pause several milliseconds
        _delay_ms(BLINK_DELAY);

        // WRITE YOUR CODE HERE
    }

    // Will never reach this
    return 0;
}







    /* Configure input pin of push button and enable internal pull-up
       resistor */
    DDRD = DDRD & ~_BV(BTN_BLUE);       // DDRD2 = 0
    PORTD = PORTD | _BV(BTN_BLUE);      // PORTD2 = 1

    // Infinite loop
    for (;;) {
        // Test if push button value is low
        if (bit_is_clear(PIND, BTN_BLUE)) {
            // Invert LED and delay
            PORTB = PORTB ^ _BV(LED_GREEN); // xor: Invert bit
            PORTB = PORTB ^ _BV(LED_RED);
            _delay_ms(BLINK_DELAY);
        }
    }

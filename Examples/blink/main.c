/***********************************************************************
 * 
 * Blink a LED and use the function from the delay library.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2018-2020 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
//#define F_CPU 16000000      // CPU frequency in Hz for delay loops
#include <util/delay.h>     // Convenience functions for busy-wait delay loops

/* Defines -----------------------------------------------------------*/
#define LED_GREEN   PB5     // Pin name where green LED is connected
#define BLINK_DELAY 1000     // Delay in miliseconds

/* Variables ---------------------------------------------------------*/

/* Function prototypes -----------------------------------------------*/

/* Functions ---------------------------------------------------------*/
/**
 * Toggle one LED and use the function from the delay library.
 */
int main(void)
{
    // Set output pin
    DDRB = DDRB | (1<<LED_GREEN);           // DDRB   OR 0010 0000

    // Set pin LOW, i.e. turn LED off
    PORTB = PORTB & ~(1<<LED_GREEN);        // PORTB AND 1101 1111

    // Infinite loop
    for (;;)
    {
        // Invert LED and delay
        PORTB = PORTB ^ (1<<LED_GREEN);     // PORTB XOR 0010 0000
        _delay_ms(BLINK_DELAY);             // Wait several miliseconds
    }

    // Will never reach this
    return 0;
}

/* Interrupt routines ------------------------------------------------*/

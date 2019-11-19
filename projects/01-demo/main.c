/***********************************************************************
 * 
 * Blink a LED with the delay function.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2018-2019 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>
#include <util/delay.h>

/* Typedef -----------------------------------------------------------*/
/* Define ------------------------------------------------------------*/
#define LED_GREEN   PB5
#define BLINK_DELAY 250

/* Variables ---------------------------------------------------------*/
/* Function prototypes -----------------------------------------------*/

/* Functions ---------------------------------------------------------*/
/* Main --------------------------------------------------------------*/
/* Toggle a LED with the delay function. */
int main(void)
{
    // Set output pin
    DDRB = DDRB | _BV(LED_GREEN);       // DDRB OR 0010 0000

    // Set pin low, ie turn LED off
    PORTB = PORTB & ~_BV(LED_GREEN);    // PORTB AND 1101 1111

    // Infinite loop
    for (;;) {
        // Invert LED and delay
        PORTB = PORTB ^ _BV(LED_GREEN); // PORTB XOR 0010 0000
        _delay_ms (BLINK_DELAY);        // Wait for several milisecs
    }

    // Will never reach this
    return (0);
}

/* Interrupts --------------------------------------------------------*/

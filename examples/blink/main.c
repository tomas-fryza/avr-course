/*
 * Blink a LED using delay.
 * (c) 2018-2024 Tomas Fryza, MIT license
 *
 * Developed using PlatformIO and AVR 8-bit Toolchain 3.6.2.
 * Tested on Arduino Uno board and ATmega328P, 16 MHz.
 */

// -- Defines --------------------------------------------------------
#define LED_BUILTIN PB5  // On-board LED
#define SHORT_DELAY 250  // Delay in milliseconds
#ifndef F_CPU
#define F_CPU 16000000   // For delay
#endif


// -- Includes -------------------------------------------------------
#include <avr/io.h>      // AVR device-specific IO definitions
#include <util/delay.h>  // Functions for busy-wait delay loops


// -- Function definitions -------------------------------------------
/*
 * Function: Main function where the program execution begins
 * Purpose:  Toggle LED using delay.
 * Returns:  none
 */
int main(void)
{
    // Set output pin in Data Direction Register
    DDRB = DDRB | (1 << LED_BUILTIN);
    // Set pin LOW in Data Register (LED off)
    PORTB = PORTB & ~(1 << LED_BUILTIN);

    // Infinite loop
    while (1)
    {
        // Pause several milliseconds
        _delay_ms(SHORT_DELAY);
        // Invert LED in Data Register
        PORTB = PORTB ^ (1 << LED_BUILTIN);
    }

    // Will never reach this
    return 0;
}

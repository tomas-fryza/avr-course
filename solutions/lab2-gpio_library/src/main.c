/***********************************************************
 * 
 * Blink a LED using GPIO library.
 * (c) 2019-2024 Tomas Fryza, MIT license
 *
 * Developed using PlatformIO and AVR 8-bit Toolchain 3.6.2.
 * Tested on Arduino Uno board and ATmega328P, 16 MHz.
 * 
 ***********************************************************/

/* Includes -----------------------------------------------*/
#include <avr/io.h>     // AVR device-specific IO definitions
#include <util/delay.h> // Functions for busy-wait delay loops
#include <gpio.h>       // GPIO library for AVR-GCC


/* Defines ------------------------------------------------*/
#define LED_GREEN PB5   // AVR pin where green LED is connected
#define LED_RED PB0
#define BTN PD2
#define SHORT_DELAY 250 // Delay in milliseconds


/* Function definitions -----------------------------------*/
/***********************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Toggle one LED and use delay library.
 * Returns:  none
 ***********************************************************/
int main(void)
{
    // Set pin(s) as output in Data Direction Register
    GPIO_mode_output(&DDRB, LED_GREEN);
    GPIO_mode_output(&DDRB, LED_RED);

    // Set pin(s) LOW in Data Register
    GPIO_write_low(&PORTB, LED_GREEN);
    GPIO_write_low(&PORTB, LED_RED);

    // Infinite loop
    while (1)
    {
        if (GPIO_read(&PIND, BTN))
        {
            // Pause several milliseconds
            _delay_ms(SHORT_DELAY);
            // Invert LED in Data Register
            GPIO_toggle(&PORTB, LED_GREEN);
            GPIO_toggle(&PORTB, LED_RED);
        }
    }

    // Will never reach this
    return 0;
}

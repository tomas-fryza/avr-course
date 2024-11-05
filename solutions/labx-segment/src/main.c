/*
 * Decimal counter using 7-segment displays.
 * (c) 2018-2024 Tomas Fryza, MIT license
 *
 * Developed using PlatformIO and AVR 8-bit Toolchain 3.6.2.
 * Tested on Arduino Uno board and ATmega328P, 16 MHz.
 */

// -- Includes -------------------------------------------------------
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include <stdlib.h>         // C library. Needed for number conversions
#include <segment.h>


// -- Global variables -----------------------------------------------
struct Counter_structure {
    uint8_t units;
    uint8_t tens;
} cnt;


// -- Function definitions -------------------------------------------
/*
 * Function: Main function where the program execution begins
 * Purpose:  Use 7-segment displays for decimal counter.
 * Returns:  none
 */
int main(void)
{
    // Initialize SSD signals
    seg_init();
    seg_show_digit(9, 3);

    // Decimal counter main clock
    TIM2_ovf_16ms();
    TIM2_ovf_enable();

    // SSD multiplexing
    TIM0_ovf_4ms();
    TIM0_ovf_enable();

    sei();

    // Infinite loop
    while (1)
    {
    }

    // Will never reach this
    return 0;
}


// -- Interrupt service routines -------------------------------------
/*
 * Function: Timer/Counter2 overflow interrupt
 * Purpose:  Increment counter every 100 ms.
 */
ISR(TIMER2_OVF_vect)
{
    static uint8_t n_ovfs = 0;

    n_ovfs++;

    // Do this every 6 x 16 ms = 100 ms
    if (n_ovfs >= 6)
    {
        n_ovfs = 0;
        cnt.units++;
        if (cnt.units > 9)
        {
            cnt.units = 0;
            cnt.tens++;
            if (cnt.tens > 9)
            {
                cnt.tens = 0;
            }
        }
    }
    // Else do nothing and exit the ISR
}


/*
 * Function: Timer/Counter0 overflow interrupt
 * Purpose:  Multiplex display positions.
 */
ISR(TIMER0_OVF_vect)
{
    static uint8_t pos = 0;

    if ((pos % 2) == 0)
        seg_show_digit(cnt.units, 0);
    else
        seg_show_digit(cnt.tens, 1);
    pos++;
}

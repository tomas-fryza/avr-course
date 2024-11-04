/*
 * Seven-segment display library for AVR-GCC.
 * (c) 2018-2024 Tomas Fryza, MIT license
 *
 * Developed using PlatformIO and AVR 8-bit Toolchain 3.6.2.
 * Tested on Arduino Uno board and ATmega328P, 16 MHz.
 */

// -- Defines --------------------------------------------------------
#ifndef F_CPU
# define F_CPU 16000000
#endif


// -- Includes -------------------------------------------------------
#include <avr/io.h>         // AVR device-specific IO definitions
#include <util/delay.h>
#include <stdlib.h>         // C library. Needed for number conversions
#include <segment.h>


// -- Function definitions -------------------------------------------
/*
 * Function: seg_init()
 * Purpose:  Configure SSD signals LATCH, CLK, and DATA as output.
 * Returns:  none
 */
void seg_init(void)
{
    /* Configuration of SSD signals */
    DDRD |= _BV(SEG_LATCH);
    DDRD |= _BV(SEG_CLK);
    DDRB |= _BV(SEG_DATA);
}


/*
 * Function: SEG_update_shift_regs()
 * Purpose:  Display segments at one position of the SSD.
 * Input:    segments - Segments to be displayed (abcdefgDP, active low)
 *           position - Position of the display where the segments are to 
 *                      be displayed (p3 p2 p1 p0 xxxx, active high)
 * Returns:  none
 */
void seg_putc(uint8_t value, uint8_t position)
{
    char string[1];
    itoa(value, string, 10);
    // TODO
    position = seg_position[position];

    // Pull LATCH, CLK, and DATA low

    // Wait 1 us

    // Loop through the 1st byte (value)
    // a b c d e f g DP (active low values)
    for (uint8_t i = 0; i < 8; i++)
    {
        // Test the LSB of "value" and output DATA value
        if ((value & 0x01) == 1)
            PORTB |= _BV(SEG_DATA);
        else
            PORTB &= ~_BV(SEG_DATA);

        // One clock period
        clk_pulse_2us();

        // Shift "value"
        value = value >> 1;
    }

    // Loop through the 2nd byte (position)
    // p3 p2 p1 p0 . . . . (active high values)
    for (uint8_t i = 0; i < 8; i++)
    {
        // Test LSB of "position" by & (faster) or % (slower) and... 
        // ...output DATA value

        // One clock period
        clk_pulse_2us();

        // Shift "position"
        position = position >> 1;
    }

    // Pull LATCH high

    // Wait 1 us

}


/*
 * Function: seg_clrscr()
 */


/*
 * Function: clk_pulse_2us()
 */
void clk_pulse_2us()
{
    _delay_us(1);
    PORTD |= _BV(SEG_CLK);
    _delay_us(1);
    PORTD &= ~_BV(SEG_CLK);
}

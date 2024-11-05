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
void seg_show_digit(uint8_t value, uint8_t position)
{
    // Segment values (abcdefgDP, active low) for numbers
    uint8_t seg_map[10] = {
    // 0     1     2     3     4     5     6     7     8     9
    0x03, 0x9f, 0x25, 0x0d, 0x99, 0x49, 0x41, 0x1f, 0x01, 0x09};

    // Digit position 3:0 (p3 p2 p1 p0 xxxx, active high)
    uint8_t seg_position[4] = {
    0x10, 0x20, 0x40, 0x80};

    // Map values 0..9
    value = seg_map[value];
    // Map positions 0..3
    position = seg_position[position];

    // Pull LATCH, CLK, and DATA low
    PORTD &= ~_BV(SEG_LATCH);
    PORTD &= ~_BV(SEG_CLK);
    PORTB &= ~_BV(SEG_DATA);

    // Wait 1 us
    _delay_us(1);

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
        // Test the LSB of "position" and output DATA value
        if ((position & 0x01) == 1)
            PORTB |= _BV(SEG_DATA);
        else
            PORTB &= ~_BV(SEG_DATA);

        // One clock period
        clk_pulse_2us();

        // Shift "position"
        position = position >> 1;
    }

    // Pull LATCH high
    PORTD |= _BV(SEG_LATCH);

    // Wait 1 us
    _delay_us(1);
}


/*
 * Function: seg_pulse_2us()
 * Purpose:  Generate one clock pulse at SEG_CLK pin with length of 2 microsecs.
 */
void clk_pulse_2us()
{
    _delay_us(1);
    PORTD |= _BV(SEG_CLK);
    _delay_us(1);
    PORTD &= ~_BV(SEG_CLK);
}


/*
 * Function: seg_clrscr()
 * Purpose:  Turn off all segments.
 */
void seg_clrscr(void)
{
    // TODO
}

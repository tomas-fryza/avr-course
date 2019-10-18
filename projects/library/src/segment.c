/***********************************************************************
 * Title:    Seven-segment display library
 * Author:   Tomas Fryza, Brno University of Technology, Czechia
 * Software: avr-gcc, tested with avr-gcc 4.9.2
 * Hardware: Any AVR
 *
 * MIT License
 *
 * Copyright (c) 2019 Tomas Fryza
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 **********************************************************************/

/* Includes ----------------------------------------------------------*/
#include <util/delay.h>
#include "gpio.h"
#include "segment.h"

/* Define ------------------------------------------------------------*/
/* Variables ---------------------------------------------------------*/
/* Active low digit 0 to 9 */
uint8_t segment_digit[] = {
   //DPgfedcba
    0b11000000,      // Digit 0
    0b11111001,      // Digit 1
    0b10100100,      // Digit 2
    // TODO: Set segments for other digits
    0b10011000};     // Digit 9

/* Active high position 0 to 3 */
uint8_t segment_position[] = {
    0b00001000,   // Position 0
    0b00000100,   // Position 1
    0b00000010,   // Position 2
    0b00000001};  // Position 3

/* Functions ---------------------------------------------------------*/
void SEG_putc(uint8_t digit,
              uint8_t position)
{
    uint8_t i;

    /* Read values from look-up tables */
    digit    = segment_digit[digit];
    position = segment_position[position];

    /* Put 1st byte to serial data */
    for (i = 0; i < 8; i++) {
        // TODO: Test and send 8 individual "digit" bits
        SEG_toggle_clk();
    }
    /* Put 2nd byte to serial data */
    for (i = 0; i < 8; i++) {
        // TODO: Test and send 8 individual "position" bits
        SEG_toggle_clk();
    }

    /* TODO: Generate 1 us latch pulse */
}

/*--------------------------------------------------------------------*/
void SEG_toggle_clk(void)
{
    /* TODO: Generate 2 us clock period */
}

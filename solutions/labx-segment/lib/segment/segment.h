#ifndef SEGMENT_H
# define SEGMENT_H

/***********************************************************************
 * 
 * Seven-segment display library for AVR-GCC.
 * 
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 *
 * Copyright (c) 2019 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 *
 **********************************************************************/

/**
 * @file 
 * @defgroup fryza_segment Seven-segment Library <segment.h>
 * @code #include <segment.h> @endcode
 *
 * @brief Seven-segment display library for AVR-GCC.
 *
 * The library contains functions for controlling the seven-segment 
 * display (SSD) using two shift registers 74HC595.
 *
 * @author Tomas Fryza, Dept. of Radio Electronics, Brno University 
 *         of Technology, Czechia
 * @copyright (c) 2019 Tomas Fryza, This work is licensed under 
 *                the terms of the MIT license
 * @{
 */

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>


/* Defines -----------------------------------------------------------*/
/**
 * @name  Definition of SSD interface
 * @note  Connection is based on Multi-function shield.
 */
#define SEG_LATCH   PD4
#define SEG_CLK     PD7
#define SEG_DATA    PB0


/*
 *  Global variables
 */
// Segment values (abcdefgDP, active low) for numbers and letters
uint8_t seg_ascii_value[128] = {
    // 0 @ 48, 1 @ 49, ..., 9 @ 57
    // A @ 65, B @ 66, ..., Z @ 90
    // a @ 97, b @ 98, ..., z @ 122
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, //   0....9
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, //  10...19
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, //  20...29
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, //  30...39
    //                                                 0     1
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x02, 0x3f, //  40...49
    // 2     3     4     5     6     7     8     9
    0x25, 0x0d, 0x99, 0x49, 0x41, 0x1f, 0x01, 0x09, 0xff, 0xff, //  50...59
    // !!!!!! PREPSAT HEXA !!!!!      A     B     C     D     E
    0xff, 0xff, 0xff, 0xff, 0xff, 0x41, 0x0d, 0x27, 0x19, 0x25, //  60...69
    // F     G     H     I     J     K     L     M     N     O
    0x65, 0x05, 0x49, 0xdb, 0x1b, 0x49, 0x2f, 0x43, 0x5d, 0x1d, //  70...79
    // P     Q     R     S     T     U     V     W     X     Y
    0x61, 0x02, 0x7d, 0x85, 0x2d, 0x0b, 0x1f, 0x1f, 0x49, 0xc9, //  80...89
    // Z                                         a     b     c
    0x31, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x41, 0x0d, 0x27, //  90...99
    // d     e     f     g     h     i     j     k     l     m
    0x19, 0x25, 0x65, 0x05, 0x49, 0xdb, 0x1b, 0x49, 0x2f, 0x43, // 100..109
    // n     o     p     q     r     s     t     u     v     w
    0x5d, 0x1d, 0x61, 0x02, 0x7d, 0x85, 0x2d, 0x0b, 0x1f, 0x1f, // 110..119
    // x     y     z
    0x49, 0xc9, 0x31, 0xff, 0xff, 0xff, 0xff, 0xff};            // 120..127

// Digit position 3:0 (p3 p2 p1 p0 xxxx, active high)
uint8_t seg_position[] = {
    0x80, 0x40, 0x20, 0x10};



/* Function prototypes -----------------------------------------------*/
/**
 * @brief  Configure SSD signals LATCH, CLK, and DATA as output.
 * @return none
 */
void seg_init(void);


/**
 * @brief  Display segments at one position of the SSD.
 * @param  segments Segments to be displayed (abcdefgDP, active low)
 * @param  position Position of the display where the segments are to 
 *                  be displayed (p3 p2 p1 p0 xxxx, active high)
 * @note   Two shift registers are connected in series, ie 16 bits are 
 *         transmitted.
 * @return none
 */
void seg_putc(uint8_t value, uint8_t position);


/* seg_clrscr */


/* clk_pulse_2us */


/** @} */

#endif

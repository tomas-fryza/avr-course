#ifndef SEGMENT_H_INCLUDED
#define SEGMENT_H_INCLUDED

/***********************************************************************
 * 
 * Seven-segment display library for AVR-GCC.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2019 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 *
 **********************************************************************/

/**
 *  @file  segment.h
 *  @brief Seven-segment display library for AVR-GCC.
 *
 *  @details
 *  The library contains functions for controlling the seven-segment 
 *  display using shift registers 74HC595.
 *
 *  @copyright (c) 2019 Tomas Fryza
 *  Dept. of Radio Electronics, Brno University of Technology, Czechia
 *  This work is licensed under the terms of the MIT license.
 */

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>

/* Define ------------------------------------------------------------*/
/** @brief Defines the interface of 7-segment display. */
#define SEGMENT_DATA    PB0
#define SEGMENT_CLK     PD7
#define SEGMENT_LATCH   PD4

/* Function prototypes -----------------------------------------------*/
/**
 *  @brief Xxx.
 *  @param xxx Xxx
 *  @param xxx Xxx
 */
void SEG_putc(uint8_t digit,
              uint8_t position);

/**
 *  @brief Xxx.
 */
void SEG_toggle_clk(void);

#endif /* SEGMENT_H_INCLUDED */

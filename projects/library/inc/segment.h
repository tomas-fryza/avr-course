#ifndef SEGMENT_H_INCLUDED
#define SEGMENT_H_INCLUDED

/***********************************************************************
 * 
 * Title:    Seven-segment display library
 * Author:   Tomas Fryza, Brno University of Technology, Czechia
 * Software: avr-gcc, tested with avr-gcc 4.9.2
 * Hardware: Any AVR
 *
 * Copyright (c) 2019 Tomas Fryza
 * This work is licensed under the terms of the MIT license.
 *
 **********************************************************************/

/**
 *  @file      segment.h
 *  @brief     Seven-segment display library for AVR-GCC.
 *
 *  @details   The library contains functions for controlling the seven-
 *             segment display using shift registers 74HC595.
 *
 *  @author    Tomas Fryza, Brno University of Technology, Czechia
 *  @date      2019-11-05
 *  @version   v1.0
 *  @copyright (c) 2019 Tomas Fryza, MIT License
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
 *  @param xxx - Xxxx
 *  @param xxx - Xxxx
 */
void SEG_putc(uint8_t digit,
              uint8_t position);

/**
 *  @brief Xxx.
 */
void SEG_toggle_clk(void);

#endif /* SEGMENT_H_INCLUDED */

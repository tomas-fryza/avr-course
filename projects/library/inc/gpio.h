#ifndef GPIO_H_INCLUDED
#define GPIO_H_INCLUDED

/***********************************************************************
 * Title:    GPIO library
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

/**
 *  @file      gpio.h
 *  @brief     GPIO library for AVR-GCC.
 *
 *  @details   The library contains functions for controlling the gpio 
 *             pin
 *
 *  @author    Tomas Fryza, Brno University of Technology, Czechia
 *  @date      2019-09-26
 *  @version   v1.0
 *  @copyright (c) 2019 Tomas Fryza, MIT License
 *
 *  @note      Based on Microchip Atmel ATmega328P manual
 */

/* Includes ----------------------------------------------------------*/
 #include <avr/io.h>

/* Define ------------------------------------------------------------*/
/** @brief ... */
#define PIN_RESET 0

/* Function prototypes -----------------------------------------------*/
/**
 *  @brief ...
 *  @param ... - 
 *  @retval ... - 
 */
void GPIO_init_pin(xxx);

#endif /* GPIO_H_INCLUDED */

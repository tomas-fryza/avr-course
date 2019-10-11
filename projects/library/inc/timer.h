#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

/***********************************************************************
 * Title:    Timer library
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
 *  @file      timer.h
 *  @brief     Timer library for AVR-GCC.
 *
 *  @details   The library contains functions for controlling the timer
 *             modulles
 *
 *  @author    Tomas Fryza, Brno University of Technology, Czechia
 *  @date      2019-10-11
 *  @version   v1.0
 *  @copyright (c) 2019 Tomas Fryza, MIT License
 *
 *  @note      Based on Microchip Atmel ATmega328P manual
 */

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>

/* Define ------------------------------------------------------------*/
/** @brief Defines the designation of each timer. */
#define TIM0 0
#define TIM1 1
#define TIM2 2

/** @brief Defines individual prescaler values for timers. */
#define TIM_PRESC_1    0
#define TIM_PRESC_8    1
#define TIM_PRESC_32   2
#define TIM_PRESC_64   3
#define TIM_PRESC_128  4
#define TIM_PRESC_256  5
#define TIM_PRESC_1024 6

/** @brief Defines individual interrupt modes for timers. */
#define TIM_OVERFLOW_DISABLE 0
#define TIM_OVERFLOW_ENABLE  1

/* Function prototypes -----------------------------------------------*/
/**
 *  @brief Xxx.
 *  @param xxx - Xxxx
 *  @retval None
 */
void TIM_config_prescaler(uint8_t timer_name,
                          uint8_t presc_val);

/**
 *  @brief Xxx.
 *  @param xxx - Xxxx
 *  @retval None
 */
void TIM_config_interrupt(uint8_t timer_name,
                          uint8_t interr_mode);

#endif /* TIMER_H_INCLUDED */

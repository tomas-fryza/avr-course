#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

/***********************************************************************
 * 
 * Title:    Timer library
 * Author:   Tomas Fryza, Brno University of Technology, Czechia
 * Software: avr-gcc, tested with avr-gcc 4.9.2
 * Hardware: Any AVR
 *
 * Copyright (c) 2019 Tomas Fryza
 * This work is licensed under the terms of the MIT license.
 *
 **********************************************************************/

/**
 *  @file      timer.h
 *  @brief     Timer library for AVR-GCC.
 *
 *  @details   The library contains functions for controlling the timer
 *             modules
 *
 *  @author    Tomas Fryza, Brno University of Technology, Czechia
 *  @date      2019-11-05
 *  @version   v1.0
 *  @copyright (c) 2019 Tomas Fryza, MIT License
 *
 *  @note      Based on Microchip Atmel ATmega328P manual
 */

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>

/* Define ------------------------------------------------------------*/
/** @brief Defines the designation of each timer. */
#define TIM0    0
#define TIM1    1
#define TIM2    2

/** @brief Defines individual prescaler values for timers. */
#define TIM_PRESC_1     0
#define TIM_PRESC_8     1
#define TIM_PRESC_32    2
#define TIM_PRESC_64    3
#define TIM_PRESC_128   4
#define TIM_PRESC_256   5
#define TIM_PRESC_1024  6
#define TIM_STOP        7

/** @brief Defines individual interrupt modes for timers. */
#define TIM_OVERFLOW_DISABLE    0
#define TIM_OVERFLOW_ENABLE     1

/* Function prototypes -----------------------------------------------*/
/**
 *  @brief Xxx.
 *  @param xxx - Xxxx
 */
void TIM_config_prescaler(uint8_t timer_name,
                          uint8_t presc_val);

/**
 *  @brief Xxx.
 *  @param xxx - Xxxx
 */
void TIM_config_interrupt(uint8_t timer_name,
                          uint8_t interr_mode);

#endif /* TIMER_H_INCLUDED */

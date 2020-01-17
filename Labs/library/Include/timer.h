#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

/***********************************************************************
 * 
 * Timer library for AVR-GCC.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2019 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 *
 **********************************************************************/

/**
 *  @file  timer.h
 *  @brief Timer library for AVR-GCC.
 *
 *  @details
 *  The library contains settings for controlling the timer modules.
 *
 *  @note
 *  Based on Microchip Atmel ATmega328P manual.
 * 
 *  @copyright (c) 2019 Tomas Fryza
 *  Dept. of Radio Electronics, Brno University of Technology, Czechia
 *  This work is licensed under the terms of the MIT license.
 */

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>

/* Define ------------------------------------------------------------*/
/** @brief Defines prescaler values for Timer0.
 *  @note  F_CPU = 16 MHz */
// TODO: Define Prescaler values for Timer0

/** @brief Defines prescaler values for Timer1.
 *  @note  F_CPU = 16 MHz */
#define TIM1_stop()             TCCR1B &= ~(_BV(CS12) | _BV(CS11) | _BV(CS10));
#define TIM1_overflow_4ms()     TCCR1B &= ~(_BV(CS12) | _BV(CS11)); TCCR1B |= _BV(CS10);
#define TIM1_overflow_33ms()    TCCR1B &= ~(_BV(CS12) | _BV(CS10)); TCCR1B |= _BV(CS11);
#define TIM1_overflow_262ms()   TCCR1B &= ~(_BV(CS12)); TCCR1B |= _BV(CS11) | _BV(CS10);
#define TIM1_overflow_1s()      TCCR1B &= ~(_BV(CS11) | _BV(CS10)); TCCR1B |= _BV(CS12);
#define TIM1_overflow_4s()      TCCR1B &= ~(_BV(CS11)); TCCR1B |= _BV(CS12) | _BV(CS10);

/** @brief Defines prescaler values for Timer2.
 *  @note  F_CPU = 16 MHz */
// TODO: Define Prescaler values for Timer2

/** @brief Defines interrupt modes for Timer0. */
// TODO: Define interrupt modes for Timer0

/** @brief Defines interrupt modes for Timer1. */
#define TIM1_overflow_enable()  TIMSK1 |= _BV(TOIE1);
#define TIM1_overflow_disable() TIMSK1 &= ~_BV(TOIE1);

/** @brief Defines interrupt modes for Timer2. */
// TODO: Define interrupt modes for Timer2

#endif /* TIMER_H_INCLUDED */

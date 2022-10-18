#ifndef TIMER_H
# define TIMER_H

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
 * @file 
 * @defgroup fryza_timer Timer Library <timer.h>
 * @code #include "timer.h" @endcode
 *
 * @brief Timer library for AVR-GCC.
 *
 * The library contains macros for controlling the timer modules.
 *
 * @note Based on Microchip Atmel ATmega328P manual and no source file
 *       is needed for the library.
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
 * @name  Definitions for 16-bit Timer/Counter1
 * @note  t_OVF = 1/F_CPU * prescaler * 2^n where n = 16, F_CPU = 16 MHz
 */
/** @brief Stop timer, prescaler 000 --> STOP */
#define TIM1_stop()           TCCR1B &= ~((1<<CS12) | (1<<CS11) | (1<<CS10));
/** @brief Set overflow 4ms, prescaler 001 --> 1 */
#define TIM1_overflow_4ms()   TCCR1B &= ~((1<<CS12) | (1<<CS11)); TCCR1B |= (1<<CS10);
/** @brief Set overflow 33ms, prescaler 010 --> 8 */
#define TIM1_overflow_33ms()  TCCR1B &= ~((1<<CS12) | (1<<CS10)); TCCR1B |= (1<<CS11);
/** @brief Set overflow 262ms, prescaler 011 --> 64 */
#define TIM1_overflow_262ms() TCCR1B &= ~(1<<CS12); TCCR1B |= (1<<CS11) | (1<<CS10);
/** @brief Set overflow 1s, prescaler 100 --> 256 */
#define TIM1_overflow_1s()    TCCR1B &= ~((1<<CS11) | (1<<CS10)); TCCR1B |= (1<<CS12);
/** @brief Set overflow 4s, prescaler // 101 --> 1024 */
#define TIM1_overflow_4s()    TCCR1B &= ~(1<<CS11); TCCR1B |= (1<<CS12) | (1<<CS10);

/** @brief Enable overflow interrupt, 1 --> enable */
#define TIM1_overflow_interrupt_enable()  TIMSK1 |= (1<<TOIE1);
/** @brief Disable overflow interrupt, 0 --> disable */
#define TIM1_overflow_interrupt_disable() TIMSK1 &= ~(1<<TOIE1);


/**
 * @name  Definitions for 8-bit Timer/Counter0
 * @note  t_OVF = 1/F_CPU * prescaler * 2^n where n = 8, F_CPU = 16 MHz
 */
// WRITE YOUR CODE HERE
/** @brief Stop timer, prescaler 000 --> STOP */
#define TIM0_stop()  TCCR0B &= ~((1<<CS02) | (1<<CS01) | (1<<CS00));

// #define TIM0_overflow_16us()  ...
// #define TIM0_overflow_128us()  ...
// #define TIM0_overflow_1ms()  ...
// #define TIM0_overflow_4ms()  ...

/** @brief Set overflow 16ms, prescaler // 101 --> 1024 */
#define TIM0_overflow_16ms()  TCCR0B &= ~(1<<CS01); TCCR0B |= (1<<CS02) | (1<<CS00);

/** @brief Enable overflow interrupt, 1 --> enable */
#define TIM0_overflow_interrupt_enable()  TIMSK0 |= (1<<TOIE0);
/** @brief Disable overflow interrupt, 0 --> disable */
#define TIM0_overflow_interrupt_disable() TIMSK0 &= ~(1<<TOIE0);


/**
 * @name  Definitions for 8-bit Timer/Counter2
 * @note  t_OVF = 1/F_CPU * prescaler * 2^n where n = 8, F_CPU = 16 MHz
 */
/** @brief Stop timer, prescaler 000 --> STOP */
#define TIM2_stop()  TCCR2B &= ~((1<<CS22) | (1<<CS21) | (1<<CS20));
/** @brief Set overflow 16ms, prescaler // 111 --> 1024 */
#define TIM2_overflow_16ms()  TCCR2B |= (1<<CS22) | (1<<CS21) | (1<<CS20);

/** @brief Enable overflow interrupt, 1 --> enable */
#define TIM2_overflow_interrupt_enable()  TIMSK2 |= (1<<TOIE2);
/** @brief Disable overflow interrupt, 0 --> disable */
#define TIM2_overflow_interrupt_disable() TIMSK2 &= ~(1<<TOIE2);


/** @} */

#endif

#ifndef GPIO_H_INCLUDED
#define GPIO_H_INCLUDED

/***********************************************************************
 * 
 * GPIO library for AVR-GCC.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2019 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 *
 **********************************************************************/

/**
 *  @file  gpio.h
 *  @brief GPIO library for AVR-GCC.
 *
 *  @details
 *  The library contains functions for controlling AVRs' gpio pin(s).
 *
 *  @note
 *  Based on AVR Libc Reference Manual.
 * 
 *  @copyright (c) 2019 Tomas Fryza
 *  Dept. of Radio Electronics, Brno University of Technology, Czechia
 *  This work is licensed under the terms of the MIT license.
 */

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>

/* Define ------------------------------------------------------------*/
/** @brief Defines logical values of IO pin. */
#define LOW     0
#define HIGH    1

/* Function prototypes -----------------------------------------------*/
/**
 *  @brief Configures one output pin.
 *  @param reg_name Data Direction Register name of IO port, such as 
 *                  DDRB, DDRD, ...
 *  @param pin_num Pin designation in the interval 0 to 7
 */
void GPIO_config_output(volatile uint8_t *reg_name,
                                 uint8_t pin_num);

/**
 *  @brief Xxx.
 *  @param reg_name Xxx
 *  @param pin_num Xxx
 *  @param pin_val Xxx
 */
void GPIO_write(volatile uint8_t *reg_name,
                         uint8_t pin_num,
                         uint8_t pin_val);

/**
 *  @brief Xxx.
 *  @param reg_name Xxx
 *  @param pin_num Xxx
 */
void GPIO_toggle(volatile uint8_t *reg_name,
                          uint8_t pin_num);

/**
 *  @brief Xxx.
 *  @param reg_name Xxx
 *  @param pin_num Xxx
 */
void GPIO_config_input_nopull(volatile uint8_t *reg_name,
                                       uint8_t pin_num);

/**
 *  @brief Xxx.
 *  @param reg_name Xxx
 *  @param pin_num Xxx
 */
void GPIO_config_input_pullup(volatile uint8_t *reg_name,
                                       uint8_t pin_num);

/**
 *  @brief  Xxx.
 *  @param reg_name Xxx
 *  @param pin_num Xxx
 *  @return Xxx
 */
uint8_t GPIO_read(volatile uint8_t *reg_name,
                           uint8_t pin_num);

#endif /* GPIO_H_INCLUDED */

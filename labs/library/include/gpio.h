#ifndef GPIO_H
# define GPIO_H

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
 * @file 
 * @defgroup fryza_gpio GPIO Library <gpio.h>
 * @code #include "gpio.h" @endcode
 *
 * @brief GPIO library for AVR-GCC.
 *
 * The library contains functions for controlling AVRs' gpio pin(s).
 *
 * @note Based on AVR Libc Reference Manual. Tested on ATmega328P 
 *       (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2.
 * @author Tomas Fryza, Dept. of Radio Electronics, Brno University 
 *         of Technology, Czechia
 * @copyright (c) 2019 Tomas Fryza, This work is licensed under 
 *                the terms of the MIT license
 * @{
 */


/* Includes ----------------------------------------------------------*/
#include <avr/io.h>


/* Function prototypes -----------------------------------------------*/
/**
 * @brief  Configure one output pin.
 * @param  reg Address of Data Direction Register, such as &DDRB
 * @param  pin Pin designation in the interval 0 to 7
 * @return none
 */
void GPIO_mode_output(volatile uint8_t *reg, uint8_t pin);


/**
 * @brief  Configure one input pin and enable pull-up.
 * @param  reg Address of Data Direction Register, such as &DDRB
 * @param  pin Pin designation in the interval 0 to 7
 * @return none
 */
void GPIO_mode_input_pullup(volatile uint8_t *reg, uint8_t pin);


/**
 * @brief  Write one pin to low value.
 * @param  reg Address of Port Register, such as &PORTB
 * @param  pin Pin designation in the interval 0 to 7
 * @return none
 */
void GPIO_write_low(volatile uint8_t *reg, uint8_t pin);


/**
 * @brief  Write one pin to high value.
 * @param  reg Address of Port Register, such as &PORTB
 * @param  pin Pin designation in the interval 0 to 7
 * @return none
 */
void GPIO_write_high(volatile uint8_t *reg, uint8_t pin);


/**
 * @brief  Read a value from input pin.
 * @param  reg Address of Pin Register, such as &PINB
 * @param  pin Pin designation in the interval 0 to 7
 * @return Pin value
 */
uint8_t GPIO_read(volatile uint8_t *reg, uint8_t pin);


/* GPIO_config_input_nopull */


/* GPIO_toggle */


/** @} */

#endif

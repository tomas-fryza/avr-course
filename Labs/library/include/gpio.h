#ifndef GPIO_H
#define GPIO_H

/***********************************************************************
 * 
 * GPIO library for AVR-GCC.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2019-2021 Tomas Fryza
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
 * @copyright (c) 2019-2021 Tomas Fryza, This work is licensed under 
 *                the terms of the MIT license
 * @{
 */


/* Includes ----------------------------------------------------------*/
#include <avr/io.h>


/* Function prototypes -----------------------------------------------*/
/**
 * @name Functions
 */

/**
 * @brief  Configure one output pin in Data Direction Register.
 * @param  reg_name Address of Data Direction Register, such as &DDRB
 * @param  pin_num  Pin designation in the interval 0 to 7
 * @return none
 */
void GPIO_config_output(volatile uint8_t *reg_name, uint8_t pin_num);


/* GPIO_config_input_nopull */


/**
 * @brief  Configure one input pin and enable pull-up.
 * @param  reg_name Address of Data Direction Register, such as &DDRB
 * @param  pin_num  Pin designation in the interval 0 to 7
 * @return none
 */
void GPIO_config_input_pullup(volatile uint8_t *reg_name, uint8_t pin_num);


/**
 * @brief  Write one pin to a low value.
 * @param  reg_name Address of Port Register, such as &PORTB
 * @param  pin_num  Pin designation in the interval 0 to 7
 * @return none
 */
void GPIO_write_low(volatile uint8_t *reg_name, uint8_t pin_num);


/* GPIO_write_high */


/* GPIO_toggle */


/**
 * @brief  Read a value from input pin.
 * @param  reg_name Address of Pin Register, such as &PINB
 * @param  pin_num  Pin designation in the interval 0 to 7
 * @return Pin value
 */
uint8_t GPIO_read(volatile uint8_t *reg_name, uint8_t pin_num);

/** @} */

#endif

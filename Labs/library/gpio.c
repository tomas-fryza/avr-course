/***********************************************************************
 * 
 * GPIO library for AVR-GCC.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2019-2020 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 *
 **********************************************************************/

/* Includes ----------------------------------------------------------*/
#include "gpio.h"

/* Function definitions ----------------------------------------------*/
void GPIO_config_output(volatile uint8_t *reg_name, uint8_t  pin_num)
{
    *reg_name = *reg_name | (1<<pin_num);
}

/*--------------------------------------------------------------------*/
/* GPIO_config_input_nopull */

/*--------------------------------------------------------------------*/
void GPIO_config_input_pullup(volatile uint8_t *reg_name, uint8_t pin_num)
{
    *reg_name = *reg_name & ~(1<<pin_num);  // Data Direction Register
    *reg_name++;    // Change pointer to Data Register
    *reg_name = *reg_name | (1<<pin_num);   // Data Register
}

/*--------------------------------------------------------------------*/
void GPIO_write_low(volatile uint8_t *reg_name, uint8_t  pin_num)
{
    *reg_name = *reg_name & ~(1<<pin_num);
}

/*--------------------------------------------------------------------*/
/* GPIO_write_high */

/*--------------------------------------------------------------------*/
/* GPIO_toggle */

/*--------------------------------------------------------------------*/
/* GPIO_read */

/***********************************************************************
 * 
 * GPIO library
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2019 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 *
 **********************************************************************/

/* Includes ----------------------------------------------------------*/
#include "gpio.h"
#include "common.h"

/* Functions ---------------------------------------------------------*/
void GPIO_config_output(volatile uint8_t *reg_name,
                                 uint8_t  pin_num) {

    *reg_name = *reg_name | _BV(pin_num);
}

/*--------------------------------------------------------------------*/
void GPIO_write(volatile uint8_t *reg_name,
                         uint8_t  pin_num,
                         uint8_t  pin_val) {

    if (pin_val == LOW)
        *reg_name = *reg_name & ~_BV(pin_num);
    else
        *reg_name = *reg_name | _BV(pin_num);
}

/*--------------------------------------------------------------------*/
/*void GPIO_toggle(volatile uint8_t *reg_name,
                          uint8_t  pin_num) {

    // TODO: Body of the function
}
*/
/*--------------------------------------------------------------------*/
/*void GPIO_config_input_nopull(volatile uint8_t *reg_name,
                                       uint8_t  pin_num) {

    // TODO: Body of the function
}
*/
/*--------------------------------------------------------------------*/
/*void GPIO_config_input_pullup(volatile uint8_t *reg_name,
                                       uint8_t  pin_num) {

    // TODO: Body of the function
}
*/
/*--------------------------------------------------------------------*/
/*uint8_t GPIO_read(volatile uint8_t *reg_name,
                           uint8_t  pin_num) {

    // TODO: Body of the function
}
*/

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
void GPIO_output(volatile uint8_t *reg, uint8_t pin) {

    *reg = *reg | _BV(pin);
}

/*--------------------------------------------------------------------*/
void GPIO_write(volatile uint8_t *reg, uint8_t pin, uint8_t val) {

    if (val == LOW)
        *reg = *reg & ~_BV(pin);
    else
        *reg = *reg | _BV(pin);
}

/*--------------------------------------------------------------------*/
/*void GPIO_toggle(volatile uint8_t *reg, uint8_t pin) {

    // TODO: Body of the function
}
*/
/*--------------------------------------------------------------------*/
/*void GPIO_input_nopull(volatile uint8_t *reg, uint8_t pin) {

    // TODO: Body of the function
}
*/
/*--------------------------------------------------------------------*/
/*void GPIO_input_pullup(volatile uint8_t *reg, uint8_t pin) {

    // TODO: Body of the function
}
*/
/*--------------------------------------------------------------------*/
/*uint8_t GPIO_read(volatile uint8_t *reg, uint8_t pin) {

    // TODO: Body of the function
}
*/

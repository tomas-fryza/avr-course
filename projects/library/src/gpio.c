/***********************************************************************
 * Title:    GPIO library
 * Author:   Tomas Fryza, Brno University of Technology, Czechia
 * Software: avr-gcc, tested with avr-gcc 4.9.2
 * Hardware: Any AVR
 *
 * Copyright (c) 2019 Tomas Fryza
 * This work is licensed under the terms of the MIT license.
 *
 **********************************************************************/

/* Includes ----------------------------------------------------------*/
#include "gpio.h"

/* Define ------------------------------------------------------------*/

/* Functions ---------------------------------------------------------*/
void GPIO_config_output(volatile uint8_t *reg_name,
                        uint8_t pin_num)
{
    *reg_name = *reg_name | _BV(pin_num);
}

/*--------------------------------------------------------------------*/
void GPIO_write(volatile uint8_t *reg_name,
                uint8_t pin_num,
                uint8_t pin_val)
{
    if (pin_val == PIN_LOW) {
        *reg_name = *reg_name & ~_BV(pin_num);
    }
    else {
        *reg_name = *reg_name | _BV(pin_num);
    }
}

/*--------------------------------------------------------------------*/
/*void GPIO_toggle(volatile uint8_t *reg_name,
                 uint8_t pin_num)
{
    // TODO: Body of the function
}
*/

/*--------------------------------------------------------------------*/
/*void GPIO_config_input_nopull(volatile uint8_t *ddr_reg_name, 
                              volatile uint8_t *port_reg_name,
                              uint8_t pin_num)
{
    // TODO: Body of the function
}
*/

/*--------------------------------------------------------------------*/
/*void GPIO_config_input_pullup(volatile uint8_t *ddr_reg_name,
                              volatile uint8_t *port_reg_name,
                              uint8_t pin_num)
{
    // TODO: Body of the function
}
*/

/*--------------------------------------------------------------------*/
/*uint8_t GPIO_read(volatile uint8_t *reg_name,
                  uint8_t pin_num)
{
    // TODO: Body of the function
}
*/

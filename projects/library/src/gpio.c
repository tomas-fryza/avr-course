/***********************************************************************
 * Title:    GPIO library
 * Author:   Tomas Fryza, Brno University of Technology, Czechia
 * Software: avr-gcc, tested with avr-gcc 4.9.2
 * Hardware: Any AVR
 *
 * MIT License
 *
 * Copyright (c) 2019 Tomas Fryza
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 **********************************************************************/

/* Includes ----------------------------------------------------------*/
#include "gpio.h"

/* Define ------------------------------------------------------------*/

/* Functions ---------------------------------------------------------*/
void GPIO_config_output(volatile uint8_t *reg_name, uint8_t pin_num)
{
    // Body of the function
    *reg_name = *reg_name | _BV(pin_num);
}

/*--------------------------------------------------------------------*/
void GPIO_write(volatile uint8_t *reg_name, uint8_t pin_num, uint8_t pin_val)
{
    // Body of the function
    if (pin_val == PIN_LOW) {
        *reg_name = *reg_name & ~_BV(pin_num);
    }
    else {
        *reg_name = *reg_name | _BV(pin_num);
    }
}

/*--------------------------------------------------------------------*/
/*void GPIO_toggle(volatile uint8_t *reg_name, uint8_t pin_num)
{
    // Body of the function
}
*/

/*--------------------------------------------------------------------*/
/*void GPIO_config_input_nopull(volatile uint8_t *ddr_reg_name, 
                              volatile uint8_t *port_reg_name,
                              uint8_t pin_num)
{
    // Body of the function
}
*/

/*--------------------------------------------------------------------*/
/*void GPIO_config_input_pullup(volatile uint8_t *ddr_reg_name,
                              volatile uint8_t *port_reg_name,
                              uint8_t pin_num)
{
    // Body of the function
}
*/

/*--------------------------------------------------------------------*/
/*uint8_t GPIO_read(volatile uint8_t *reg_name, uint8_t pin_num)
{
    // Body of the function
}
*/

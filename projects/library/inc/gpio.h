#ifndef GPIO_H_INCLUDED
#define GPIO_H_INCLUDED

/***********************************************************************
 * 
 * Title:    GPIO library
 * Author:   Tomas Fryza, Brno University of Technology, Czechia
 * Software: avr-gcc, tested with avr-gcc 4.9.2
 * Hardware: Any AVR
 *
 * Copyright (c) 2019 Tomas Fryza
 * This work is licensed under the terms of the MIT license.
 *
 **********************************************************************/

/**
 *  @file      gpio.h
 *  @brief     GPIO library for AVR-GCC.
 *
 *  @details   The library contains functions for controlling the gpio 
 *             pin(s)
 *
 *  @author    Tomas Fryza, Brno University of Technology, Czechia
 *  @date      2019-11-05
 *  @version   v1.0
 *  @copyright (c) 2019 Tomas Fryza, MIT License
 *
 *  @note      Based on Microchip Atmel ATmega328P manual
 */

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>

/* Define ------------------------------------------------------------*/
/** @brief Defines logical values of IO pin. */
#define PIN_LOW     0
#define PIN_HIGH    1

/* Function prototypes -----------------------------------------------*/
/**
 *  @brief Configures one output pin.
 *  @param reg_name - Data Direction Register name of IO port, such as 
 *                    DDRB, DDRD, ...
 *  @param pin_num - Pin designation in the interval 0 to 7
 */
void GPIO_config_output(volatile uint8_t *reg_name,
                        uint8_t pin_num);

void GPIO_write(volatile uint8_t *reg_name,
                uint8_t pin_num,
                uint8_t pin_val);

void GPIO_toggle(volatile uint8_t *reg_name,
                 uint8_t pin_num);

void GPIO_config_input_nopull(volatile uint8_t *ddr_reg_name, 
                              volatile uint8_t *port_reg_name,
                              uint8_t pin_num);

void GPIO_config_input_pullup(volatile uint8_t *ddr_reg_name,
                              volatile uint8_t *port_reg_name,
                              uint8_t pin_num);

/**
 *  @brief Xxx.
 *  @param xxx - Xxxx
 *  @param xxx - Xxxx
 *  @return Xxx
 */
uint8_t GPIO_read(volatile uint8_t *reg_name,
                  uint8_t pin_num);

#endif /* GPIO_H_INCLUDED */

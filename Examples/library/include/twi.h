#ifndef TWI_H
#define TWI_H

/***********************************************************************
 * 
 * TWI library for AVR-GCC.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2018-2021 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 *
 **********************************************************************/

/**
 * @mainpage
 * Collection of AVR libraries for the course Digital Electronics 2, 
 * Brno University of Technology, Czechia
 * @author Tomas Fryza, Peter Fleury
 * @copyright (c) 2018-2021 Tomas Fryza, This work is licensed under 
 *                the terms of the MIT license
 *
 * @file 
 * @defgroup fryza_twi TWI Library <twi.h>
 * @code #include "twi.h" @endcode
 *
 * @brief TWI library for AVR-GCC.
 *
 * This library defines functions for the TWI (I2C) communication between
 * AVR and slave device(s). Functions use internal TWI module of AVR.
 *
 * @note Based on Microchip Atmel ATmega16 and ATmega328P manuals.
 * @author Tomas Fryza, Dept. of Radio Electronics, Brno University 
 *         of Technology, Czechia
 * @copyright (c) 2018-2021 Tomas Fryza, This work is licensed under 
 *                the terms of the MIT license
 * @{
 */

/* Includes ----------------------------------------------------------*/
 #include <avr/io.h>

/* Defines -----------------------------------------------------------*/
/**
 * @name Definition of frequencies 
 */
#ifndef F_CPU
# define F_CPU 16000000 /**< @brief CPU frequency in Hz required for delay */
#endif
#define F_SCL 50000 /**< @brief TWI bit rate. Must be greater than 31000 */
#define TWI_BIT_RATE_REG ((F_CPU/F_SCL - 16) / 2) /**< @brief TWI bit rate register value */


/**
 * @name Definition of ports and pins
 */
#define TWI_PORT PORTC /**< @brief Port of TWI hardware unit */
#define TWI_SDA_PIN 4 /**< @brief SDA pin of TWI hardware unit */
#define TWI_SCL_PIN 5 /**< @brief SCL pin of TWI hardware unit */


/**
 * @name Other definitions
 */
#define TWI_READ 1 /**< @brief Data direction for reading from TWI device */
#define TWI_WRITE 0 /**< @brief Data direction for writing to TWI device */
/** @brief Define address of Data Direction Register of port _x */
#define DDR(_x) (*(&_x - 1))
/** @brief Define address of input register of port _x */
#define PIN(_x) (*(&_x - 2))


/* Function prototypes -----------------------------------------------*/
/**
 * @name Functions
 */

/**
 * @brief  Initialize TWI, enable internal pull-ups, set SCL frequency.
 * @par    Implementation notes:
 *           - AVR internal pull-up resistors at pins TWI_SDA_PIN and
 *             TWI_SCL_PIN are enabled
 *           - TWI bit rate register value is calculated as follows
 *             fscl = fcpu/(16 + 2*TWBR)
 * @return none
 */
void twi_init(void);


/**
 * @brief  Start communication on TWI bus and send address of TWI slave.
 * @param  slave_address SLA+R or SLA+W address
 * @retval 0 - Slave device accessible
 * @retval 1 - Failed to access slave device
 * @note   Function returns 0 only if 0x18 or 0x40 status code is detected\n
 *           0x18: SLA+W has been transmitted and ACK has been received\n
 *           0x40: SLA+R has been transmitted and ACK has been received\n
 */
uint8_t twi_start(uint8_t slave_address);


/**
 * @brief  Send one data byte to TWI slave device.
 * @param  data Byte to be transmitted
 * @return none
 */
void twi_write(uint8_t data);


/**
 * @brief  Read one byte from TWI slave device and acknowledge it by ACK.
 * @return Received data byte
 */
uint8_t twi_read_ack(void);


/**
 * @brief  Read one byte from TWI slave device and acknowledge it by NACK.
 * @return Received data byte
 */
uint8_t twi_read_nack(void);


/**
 * @brief  Generates stop condition on TWI bus.
 * @return none
 */
void twi_stop(void);

/** @} */

#endif

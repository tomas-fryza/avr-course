#ifndef TWI_H
# define TWI_H

/***********************************************************************
 * 
 * I2C/TWI library for AVR-GCC.
 * 
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 *
 * Copyright (c) 2018 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 *
 **********************************************************************/

/**
 * @mainpage
 * Collection of AVR libraries for the course Digital Electronics 2, 
 * Brno University of Technology, Czechia
 * @author Tomas Fryza, Peter Fleury
 * @copyright (c) 2018 Tomas Fryza, This work is licensed under 
 *                the terms of the MIT license
 *
 * @file 
 * @defgroup fryza_twi TWI Library <twi.h>
 * @code #include <twi.h> @endcode
 *
 * @brief I2C/TWI library for AVR-GCC.
 *
 * This library defines functions for the TWI (I2C) communication between
 * AVR and Slave device(s). Functions use internal TWI module of AVR.
 *
 * @note Based on Microchip Atmel ATmega16 and ATmega328P manuals.
 * @author Tomas Fryza, Dept. of Radio Electronics, Brno University 
 *         of Technology, Czechia
 * @copyright (c) 2018 Tomas Fryza, This work is licensed under 
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
# define F_CPU 16000000 /**< @brief CPU frequency in Hz required TWI_BIT_RATE_REG */
#endif
#define F_SCL 50000 /**< @brief I2C/TWI bit rate. Must be greater than 31000 */
#define TWI_BIT_RATE_REG ((F_CPU/F_SCL - 16) / 2) /**< @brief TWI bit rate register value */


/**
 * @name Definition of ports and pins
 */
#define TWI_PORT PORTC /**< @brief Port of TWI unit */
#define TWI_SDA_PIN 4 /**< @brief SDA pin of TWI unit */
#define TWI_SCL_PIN 5 /**< @brief SCL pin of TWI unit */


/**
 * @name Other definitions
 */
#define TWI_READ 1 /**< @brief Mode for reading from I2C/TWI device */
#define TWI_WRITE 0 /**< @brief Mode for writing to I2C/TWI device */
/** @brief Define address of Data Direction Register of port _x */
#define DDR(_x) (*(&_x - 1))
/** @brief Define address of input register of port _x */
#define PIN(_x) (*(&_x - 2))


/* Function prototypes -----------------------------------------------*/
/**
 * @brief  Initialize TWI unit, enable internal pull-ups, and set SCL frequency.
 * @par    Implementation notes:
 *           - AVR internal pull-up resistors at pins TWI_SDA_PIN and
 *             TWI_SCL_PIN are enabled
 *           - TWI bit rate register value is calculated as follows
 *             fscl = fcpu/(16 + 2*TWBR)
 * @return none
 */
void twi_init(void);


/**
 * @brief  Start communication on I2C/TWI bus and send address byte.
 * @param  address Slave address
 * @param  mode TWI_READ or TWI_WRITE
 * @retval 0 - Slave device accessible
 * @retval 1 - Failed to access Slave device
 * @note   Function returns 0 only if 0x18 or 0x40 status code is detected\n
 *           0x18: SLA+W has been transmitted and ACK has been received\n
 *           0x40: SLA+R has been transmitted and ACK has been received\n
 */
uint8_t twi_start(uint8_t address, uint8_t mode);


/**
 * @brief  Send one data byte to I2C/TWI Slave device.
 * @param  data Byte to be transmitted
 * @return none
 */
void twi_write(uint8_t data);


/**
 * @brief  Read one byte from the I2C/TWI Slave device and acknowledge
 *         it with ACK, i.e. communication will continue.
 * @return Received data byte
 */
uint8_t twi_read_ack(void);


/**
 * @brief  Read one byte from the I2C/TWI Slave device and acknowledge
 *         it with NACK, i.e. communication will not continue.
 * @return Received data byte
 */
uint8_t twi_read_nack(void);


/**
 * @brief  Generates stop condition on I2C/TWI bus.
 * @return none
 */
void twi_stop(void);


/** @} */

#endif

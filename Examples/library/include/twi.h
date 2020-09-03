#ifndef TWI_H_INCLUDED
#define TWI_H_INCLUDED

/***********************************************************************
 * 
 * TWI library for AVR-GCC.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2018-2019 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 *
 **********************************************************************/

/**
 * @file  twi.h
 * TWI library for AVR-GCC.
 *
 * @details
 * The library defines functions for the TWI (I2C) communication between
 * AVR and slave device(s). Functions use TWI module of AVR.
 *
 * @note
 * Based on Microchip Atmel ATmega16 and ATmega328P manuals.
 * 
 * @copyright (c) 2018-2019 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 */

/* Includes ----------------------------------------------------------*/
 #include <avr/io.h>

/* Defines -----------------------------------------------------------*/
/** Port of TWI hardware unit. */
#define TWI_PORT    PORTC
/** SDA pin of TWI hardware unit. */
#define TWI_SDA_PIN 4
/** SCL pin of TWI hardware unit. */
#define TWI_SCL_PIN 5

/**
 * TWI bit rate.
 * @warning Must be greater than 31000 kbps.
 */
#define F_SCL       50000

/** TWI bit rate register value. */
#define TWI_BIT_RATE_REG ((F_CPU/F_SCL - 16) / 2)

/** Data direction for reading from TWI device. */
#define TWI_READ    1
/** Data direction for writing to TWI device. */
#define TWI_WRITE   0

/* Function prototypes -----------------------------------------------*/
/**
 * Initialize TWI, enable internal pull-up resistors, and set SCL 
 * frequency.
 * @par Implementation notes:
 *    - AVR internal pull-up resistors at pins TWI_SDA_PIN and
 *      TWI_SCL_PIN are enabled
 *    - TWI bit rate register value is calculated as follows
 *      fscl = fcpu/(16 + 2*TWBR)
 */
void twi_init(void);

/**
 * Start communication on TWI bus and send address of TWI slave.
 * @param  slave_address Address and transfer direction of TWI slave.
 * @retval 0 - Slave device accessible.
 * @retval 1 - Failed to access slave device.
 * @note Function returns 0 only if 0x18 or 0x40 status code is detected.
 *       0x18: SLA+W has been transmitted and ACK has been received.
 *       0x40: SLA+R has been transmitted and ACK has been received.
 */
uint8_t twi_start(uint8_t slave_address);

/**
 * Send one byte to TWI slave device.
 * @param data Byte to be transmitted.
 */
void twi_write(uint8_t data);

/**
 * Read one byte from TWI slave device, followed by ACK.
 * @return Received data.
 */
uint8_t twi_read_ack(void);

/**
 * Read one byte from TWI slave device, followed by NACK.
 * @return Received data.
 */
uint8_t twi_read_nack(void);

/** Generates stop condition on TWI bus. */
void twi_stop(void);

#endif /* TWI_H_INCLUDED */

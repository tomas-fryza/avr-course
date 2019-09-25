#ifndef TWI_H_INCLUDED
#define TWI_H_INCLUDED

/***********************************************************************
 * Title:    TWI library
 * Author:   Tomas Fryza, Brno University of Technology, Czechia
 * Software: avr-gcc, tested with avr-gcc 4.9.2
 * Hardware: Any AVR with built-in TWI unit
 *
 * MIT License
 *
 * Copyright (c) 2018 Tomas Fryza
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

/**
 *  @file      twi.h
 *  @brief     TWI library for AVR-GCC.
 *
 *  @details   The library defines functions for the TWI (I2C)
 *  communication between AVR and slave device(s). Functions use TWI
 *  unit of AVR.
 *
 *  @author    Tomas Fryza, Brno University of Technology, Czechia
 *  @date      2019-04-30
 *  @version   v2.1
 *  @copyright (c) 2018 Tomas Fryza, MIT License
 *
 *  @note      Based on Atmel ATmega16 and ATmega328P manuals
 */

/* Includes ----------------------------------------------------------*/
 #include <avr/io.h>

/* Define ------------------------------------------------------------*/
/** @brief Port of TWI hardware unit. */
#define TWI_PORT PORTC

/** @brief SDA pin of TWI hardware unit. */
#define TWI_SDA_PIN 4

/** @brief SCL pin of TWI hardware unit. */
#define TWI_SCL_PIN 5

/** @brief TWI bit rate.
 *  @warning Must be greater than 31000 kbps */
#define F_SCL 50000

/** @brief TWI bit rate register value. */
#define TWI_BIT_RATE_REG ((F_CPU/F_SCL - 16) / 2)

/** @brief Data direction for reading from TWI device. */
#define TWI_READ 1

/** @brief Data direction for writing to TWI device. */
#define TWI_WRITE 0

/* Function prototypes -----------------------------------------------*/
/**
 *  @brief Initialize TWI, enable internal pull-up resistors, and set
 *         SCL frequency.
 *  @par Implementation notes:
 *     - AVR internal pull-up resistors at pins TWI_SDA_PIN and
 *       TWI_SCL_PIN are enabled
 *     - TWI bit rate register value is calculated as follows
 *       fscl = fcpu/(16 + 2*TWBR)
 */
void twi_init(void);


/**
 *  @brief Start communication on TWI bus and send address of TWI slave.
 *  @param slave_address - Address and transfer direction of TWI slave
 *  @retval 0 - Slave device accessible
 *  @retval 1 - Failed to access slave device
 *  @Note Function returns 0 only if 0x18 or 0x40 status code is detected.
 *        0x18: SLA+W has been transmitted and ACK has been received
 *        0x40: SLA+R has been transmitted and ACK has been received
 */
uint8_t twi_start(uint8_t slave_address);


/**
 *  @brief Send one byte to TWI slave device.
 *  @param data - Byte to be transmitted
 */
void twi_write(uint8_t data);


/**
 *  @brief Read one byte from TWI slave device, followed by ACK.
 *  @return Received data
 */
uint8_t twi_read_ack(void);


/**
 *  @brief Read one byte from TWI slave device, followed by NACK.
 *  @return Received data
 */
uint8_t twi_read_nack(void);


/**
 *  @brief Generates stop condition on TWI bus.
 */
void twi_stop(void);

#endif /* TWI_H_INCLUDED */

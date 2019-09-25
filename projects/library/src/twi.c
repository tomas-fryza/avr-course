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

/* Includes ----------------------------------------------------------*/
#include "twi.h"

/* Define ------------------------------------------------------------*/
/* Address of data direction register of port x */
#define DDR(x) (*(&x - 1))

/* Functions ---------------------------------------------------------*/
void twi_init(void)
{
    /* Enable internal pull-up resistors */
    DDR(TWI_PORT) &= ~(_BV(TWI_SDA_PIN) | _BV(TWI_SCL_PIN));
    TWI_PORT |= _BV(TWI_SDA_PIN) | _BV(TWI_SCL_PIN);

    /* Set SCL frequency */
    TWSR &= ~(_BV(TWPS1) | _BV(TWPS0));
    TWBR = TWI_BIT_RATE_REG;
}


/*--------------------------------------------------------------------*/
uint8_t twi_start(uint8_t slave_address)
{
    uint8_t twi_response;

    /* Generate start condition on TWI bus */
    TWCR = _BV(TWINT) | _BV(TWSTA) | _BV(TWEN);
    while ((TWCR & _BV(TWINT)) == 0);

    /* Send SLA+R or SLA+W frame on TWI bus */
    TWDR = slave_address;
    TWCR = _BV(TWINT) | _BV(TWEN);
    while ((TWCR & _BV(TWINT)) == 0);

    /* Check TWI Status Register and mask TWI prescaler bits */
    twi_response = TWSR & 0xf8;
    /* Status Code 0x18: SLA+W has been transmitted and ACK received
                   0x40: SLA+R has been transmitted and ACK received */
        if (twi_response == 0x18 || twi_response == 0x40) {
        return 0;   /* Slave device accessible */
    }
    else {
        return 1;   /* Failed to access slave device */
    }
}


/*--------------------------------------------------------------------*/
void twi_write(uint8_t data)
{
    TWDR = data;
    TWCR = _BV(TWINT) | _BV(TWEN);
    while ((TWCR & _BV(TWINT)) == 0);
}


/*--------------------------------------------------------------------*/
uint8_t twi_read_ack(void)
{
	TWCR = _BV(TWINT) | _BV(TWEN) | _BV(TWEA);
    while ((TWCR & _BV(TWINT)) == 0);
	return (TWDR);
}


/*--------------------------------------------------------------------*/
uint8_t twi_read_nack(void)
{
	TWCR = _BV(TWINT) | _BV(TWEN);
    while ((TWCR & _BV(TWINT)) == 0);
	return (TWDR);
}


/*--------------------------------------------------------------------*/
void twi_stop(void)
{
    TWCR = _BV(TWINT) | _BV(TWSTO) | _BV(TWEN);
}

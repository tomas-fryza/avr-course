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

/* Includes ----------------------------------------------------------*/
#include "include/twi.h"
#include "include/common.h"

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
    if (twi_response == 0x18 || twi_response == 0x40)
    {
        return 0;   /* Slave device accessible */
    }
    else
    {
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

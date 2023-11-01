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


/* Includes ----------------------------------------------------------*/
#include <twi.h>


/* Functions ---------------------------------------------------------*/
/**********************************************************************
 * Function: twi_init()
 * Purpose:  Initialize TWI unit, enable internal pull-ups, and set SCL
 *           frequency.
 * Returns:  none
 **********************************************************************/
void twi_init(void)
{
    /* Enable internal pull-up resistors */
    DDR(TWI_PORT) &= ~((1<<TWI_SDA_PIN) | (1<<TWI_SCL_PIN));
    TWI_PORT |= (1<<TWI_SDA_PIN) | (1<<TWI_SCL_PIN);

    /* Set SCL frequency */
    TWSR &= ~((1<<TWPS1) | (1<<TWPS0));
    TWBR = TWI_BIT_RATE_REG;
}


/**********************************************************************
 * Function: twi_start()
 * Purpose:  Start communication on I2C/TWI bus.
 * Returns:  none
 **********************************************************************/
void twi_start(void)
{
    /* Send Start condition */
    TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
    while ((TWCR & (1<<TWINT)) == 0);
}


/**********************************************************************
 * Function: twi_write()
 * Purpose:  Send one byte to I2C/TWI Slave device.
 * Input:    data Byte to be transmitted
 * Returns:  ACK/NACK received value
 **********************************************************************/
uint8_t twi_write(uint8_t data)
{
    uint8_t twi_status;

    /* Send SLA+R, SLA+W, or data byte on I2C/TWI bus */
    TWDR = data;
    TWCR = (1<<TWINT) | (1<<TWEN);
    while ((TWCR & (1<<TWINT)) == 0);

    /* Check value of TWI status register */
    twi_status = TWSR & 0xf8;

    /* Status Code:
          * 0x18: SLA+W has been transmitted and ACK received
          * 0x28: Data byte has been transmitted and ACK has been received
          * 0x40: SLA+R has been transmitted and ACK received
    */
    if (twi_status == 0x18 || twi_status == 0x28 || twi_status == 0x40)
        return 0;   /* ACK received */
    else
        return 1;   /* NACK received */
}


/**********************************************************************
 * Function: twi_read()
 * Purpose:  Read one byte from I2C/TWI Slave device and acknowledge
 *           it by ACK or NACK.
 * Input:    ack ACK/NACK value to be transmitted
 * Returns:  Received data byte
 **********************************************************************/
uint8_t twi_read(uint8_t ack)
{
    if (ack == TWI_ACK)
        TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
    else
        TWCR = (1<<TWINT) | (1<<TWEN);
    while ((TWCR & (1<<TWINT)) == 0);

    return (TWDR);
}


/**********************************************************************
 * Function: twi_stop()
 * Purpose:  Generates Stop condition on I2C/TWI bus.
 * Returns:  none
 **********************************************************************/
void twi_stop(void)
{
    /* Generate Stop condition on I2C/TWI bus */
    TWCR = (1<<TWINT) | (1<<TWSTO) | (1<<TWEN);
}


/**********************************************************************
 * Function: twi_test_address()
 * Purpose:  Test presence of one I2C device on the bus.
 * Input:    adr Slave address
 * Returns:  ACK/NACK received value
 **********************************************************************/
uint8_t twi_test_address(uint8_t adr)
{
    uint8_t ack;  // ACK response from Slave

    twi_start();
    ack = twi_write((adr<<1) | TWI_WRITE);
    twi_stop();

    return ack;
}

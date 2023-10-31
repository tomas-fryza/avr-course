/***********************************************************************
 * 
 * The I2C (TWI) bus scanner tests all addresses and detects devices
 * that are connected to the SDA and SCL signals.
 * 
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 *
 * Copyright (c) 2023 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/


/* Defines -----------------------------------------------------------*/
#ifndef F_CPU
# define F_CPU 16000000  // CPU frequency in Hz required for UART_BAUD_SELECT
#endif


/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include <twi.h>            // I2C/TWI library for AVR-GCC
#include <uart.h>           // Peter Fleury's UART library


/* Global variables --------------------------------------------------*/


/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Call scanning function and test all I2C (TWI) combinations.
 *           Detected devices are sent to UART.
 * Note:     UART baud rate must be greater than default, eg. 115200.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    twi_init();

    // Initialize USART to asynchronous, 8-N-1, 115200 Bd
    uart_init(UART_BAUD_SELECT(115200, F_CPU));
    sei();  // Needed for UART

    uart_puts("Scanning I2C... ");
    twi_scan();

    while (1) {
        ;
    }

    return 0;
}


/* Interrupt service routines ----------------------------------------*/

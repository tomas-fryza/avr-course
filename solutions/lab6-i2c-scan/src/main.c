/***********************************************************************
 * 
 * The I2C (TWI) bus scanner tests all addresses and detects devices
 * that are connected to the SDA and SCL signals.
 * (c) 2023-2024 Tomas Fryza, MIT license
 *
 * Developed using PlatformIO and AVR 8-bit Toolchain 3.6.2.
 * Tested on Arduino Uno board and ATmega328P, 16 MHz.
 * 
 **********************************************************************/

/* Defines -----------------------------------------------------------*/


/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include <twi.h>            // I2C/TWI library for AVR-GCC
#include <uart.h>           // Peter Fleury's UART library
#include <stdlib.h>         // C library. Needed for number conversions


/* Global variables --------------------------------------------------*/


/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Call function to test all I2C (TWI) combinations and send
 *           detected devices to UART.
 * Returns:  none
 * 
 * Some known devices:
 *     0x3c - OLED display
 *     0x57 - EEPROM
 *     0x5c - Temp+Humid
 *     0x68 - RTC
 *     0x68 - GY521
 *     0x76 - BME280
 **********************************************************************/
int main(void)
{
    char string[2];  // For converting numbers by itoa()

    twi_init();

    // Initialize USART to asynchronous, 8-N-1, 115200 Bd
    uart_init(UART_BAUD_SELECT(115200, F_CPU));

    sei();  // Needed for UART

    uart_puts("Scanning I2C... ");
    for (uint8_t sla = 8; sla < 120; sla++)
    {
        if (twi_test_address(sla) == 0)  // If ACK from Slave
        {
            uart_puts("\r\n0x");
            itoa(sla, string, 16);
            uart_puts(string);
        }
    }

    while (1) {
        ;
    }

    return 0;
}


/* Interrupt service routines ----------------------------------------*/

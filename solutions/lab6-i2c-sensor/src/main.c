/* 
 * Read values from I2C (TWI) temperature/humidity sensor and send
 * them to UART.
 * (c) 2017-2024 Tomas Fryza, MIT license
 *
 * Developed using PlatformIO and AVR 8-bit Toolchain 3.6.2.
 * Tested on Arduino Uno board and ATmega328P, 16 MHz.
 */

// -- Includes -------------------------------------------------------
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include <twi.h>            // I2C/TWI library for AVR-GCC
#include <uart.h>           // Peter Fleury's UART library
#include <stdlib.h>         // C library. Needed for number conversions


// -- Defines --------------------------------------------------------
#define DHT_ADR 0x5c
#define DHT_HUM_MEM 0
#define DHT_TEMP_MEM 2

#define RTC_ADR 0x68
#define RTC_SEC_MEM 0


// -- Global variables -----------------------------------------------
volatile uint8_t update_uart = 0;
volatile uint8_t dht12_values[5];


// -- Function definitions -------------------------------------------
/*
 * Function: Main function where the program execution begins
 * Purpose:  Wait for new data from the sensor and sent them to UART.
 * Returns:  none
 */
int main(void)
{
    char string[3];  // String for converting numbers by itoa()

    twi_init();
    uart_init(UART_BAUD_SELECT(115200, F_CPU));

    sei();  // Needed for UART

    // Test if sensor is ready
    if (twi_test_address(DHT_ADR) != 0)
    {
        uart_puts("[ERROR] I2C device not detected\r\n");
        while (1);
    }

    // Timer1
    TIM1_ovf_1sec();
    TIM1_ovf_enable();

    // Infinite loop
    while (1)
    {
        if (update_uart == 1)
        {
            // Display temperature
            itoa(dht12_values[2], string, 10);
            uart_puts(string);
            uart_puts(".");
            itoa(dht12_values[3], string, 10);
            uart_puts(string);
            uart_puts(" °C\t\t");

            // Display humidity
            itoa(dht12_values[0], string, 10);
            uart_puts(string);
            uart_puts(".");
            itoa(dht12_values[1], string, 10);
            uart_puts(string);
            uart_puts(" \%\t\t");

            // Display checksum
            itoa(dht12_values[4], string, 10);
            uart_puts(string);
            uart_puts("\r\n");

            // Do not print it again and wait for the new data
            update_uart = 0;
        }
    }

    // Will never reach this
    return 0;
}


// -- Interrupt service routines -------------------------------------
/*
 * Function: Timer/Counter1 overflow interrupt
 * Purpose:  Read data from DHT12 sensor, SLA = 0x5c.
 */
ISR(TIMER1_OVF_vect)
{
    static uint8_t n_ovfs = 0;

    n_ovfs++;
    // Read the data every 5 secs
    if (n_ovfs >= 5)
    {
        n_ovfs = 0;
        twi_readfrom_mem_into(DHT_ADR, DHT_HUM_MEM, dht12_values, 5);
        update_uart = 1;
    }
}



/*
    // Read Temp from BME280; SLA = 0x76
    sla = 0x76;
    twi_start();
    ack = twi_write((sla<<1) | TWI_WRITE);
    if (ack == 0) {       // Slave device accessible
        twi_write(0xd0);  // chip_id suppose to be 0x60
        twi_stop();
        twi_start();
        twi_write((sla<<1) | TWI_READ);
        uint8_t value = twi_read(TWI_NACK);
        twi_stop();

        // Send value(s) to UART
        itoa(value, string, 16);
        uart_puts(string);
        uart_puts("\t");
    }
*/



/*
    // MPU-6050 reset
    // twi_start();
    // twi_write((0x68<<1) | TWI_WRITE);
    // twi_write(0x6b);
    // twi_write(0x00);
    // twi_stop();
*/

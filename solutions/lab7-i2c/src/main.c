/***********************************************************************
 * 
 * The I2C (TWI) bus scanner tests all addresses and detects chips and
 * modules that are connected to the SDA and SCL signals.
 * 
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 *
 * Copyright (c) 2017 Tomas Fryza
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
#include "timer.h"          // Timer library for AVR-GCC
#include <twi.h>            // I2C/TWI library for AVR-GCC
#include <uart.h>           // Peter Fleury's UART library
#include <stdlib.h>         // C library. Needed for number conversions


/* Global variables --------------------------------------------------*/
// Declaration of "dht12" variable with structure "DHT_values_structure"
struct DHT_values_structure {
    uint8_t humidInt;
    uint8_t humidDec;
    uint8_t tempInt;
    uint8_t tempDec;
    uint8_t checksum;
} dht12;

// Declaration of "rtc" variable with structure "RTC_values_structure"
struct RTC_values_structure {
    uint8_t secs;
    uint8_t mins;
    uint8_t hours;
} rtc;


/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Use Timer/Counter1, send one I2C (TWI) address every 33 ms,
 *           and test all combinations. Send information about scanning
 *           process to UART.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    // Initialize TWI (I2C)
    twi_init();

    // Initialize USART to asynchronous, 8N1, 9600
    uart_init(UART_BAUD_SELECT(9600, F_CPU));

    // Configure 16-bit Timer/Counter1 to test one I2C address
    // Set prescaler to 33 ms and enable interrupt
    TIM1_overflow_33ms();
    // TIM1_overflow_262ms();
    TIM1_overflow_interrupt_enable();

    // Enables interrupts by setting the global interrupt mask
    sei();

    // Put strings to ringbuffer for transmitting via UART
    // uart_puts("Scan I2C bus for devices:\r\n");

    // MPU-6050 reset
    // twi_start();
    // twi_write((0x68<<1) | TWI_WRITE);
    // twi_write(0x6b);
    // twi_write(0x00);
    // twi_stop();

    // Infinite loop
    while (1)
    {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines ISRs */
    }

    // Will never reach this
    return 0;
}


/* Interrupt service routines ----------------------------------------*/
/**********************************************************************
 * Function: Timer/Counter1 overflow interrupt
 * Purpose:  Test one I2C Slave address from the range 8 to 119.
 **********************************************************************/
ISR(TIMER1_OVF_vect)
{
    static uint8_t sla = 8;  // I2C Slave address
    uint8_t ack;             // ACK response from Slave
    char string[3];          // String for converting numbers by itoa()

    // I2C scanner
    if (sla < 120) {
        twi_start();
        ack = twi_write((sla<<1) | TWI_WRITE);
        twi_stop();

        itoa(sla, string, 10);
        uart_puts(string);

        itoa(sla, string, 2);
        uart_puts("\tBin: ");
        uart_puts(string);

        itoa(sla, string, 16);
        uart_puts("\tHex: ");
        uart_puts(string);

        if (ack == 0) {  // ACK
            uart_puts("\t");
            uart_puts("OK");
        }

        sla++;
        uart_puts("\r\n");

        // Known devices:
        // 0x57 ... EEPROM
        // 0x5c ... Temp+Humid
        // 0x68 ... RTC
        // 0x68 ... GY521
        // 0x76 ... BME280
    }

/*
    // Read temperature and humidity from DHT12, SLA = 0x5c
    sla = 0x5c;
    twi_start();
    ack = twi_write((sla<<1) | TWI_WRITE);
    if (ack == 0) {
        // twi_write(0x02);  // 0x02 @ Temperature
        twi_write(0x00);  // 0x00 @ Humidity
        twi_stop();
        twi_start();
        twi_write((sla<<1) | TWI_READ);
        dht12.humidInt = twi_read(TWI_ACK);
        dht12.humidDec = twi_read(TWI_ACK);
        dht12.tempInt = twi_read(TWI_ACK);
        dht12.tempDec = twi_read(TWI_NACK);
        twi_stop();

        // Print Humidity
        itoa(dht12.humidInt, string, 10);
        uart_puts(string);
        uart_puts(".");
        itoa(dht12.humidDec, string, 10);
        uart_puts(string);
        uart_puts(" %\t");

        // Print Temperature
        itoa(dht12.tempInt, string, 10);
        uart_puts(string);
        uart_puts(".");
        itoa(dht12.tempDec, string, 10);
        uart_puts(string);
        uart_puts(" °C\r\n");
    }
*/
/*
    // Read Time from RTC DS3231; SLA = 0x68
    // FYI: MPU-6050; SLA = 0x68
    sla = 0x68;
    twi_start();
    ack = twi_write((sla<<1) | TWI_WRITE);
    if (ack == 0) {       // Slave device accessible
        twi_write(0x00);  // 0x00: Seconds
        twi_stop();
        twi_start();
        twi_write((sla<<1) | TWI_READ);
        rtc.secs = twi_read(TWI_ACK);
        rtc.mins = twi_read(TWI_ACK);
        rtc.hours = twi_read(TWI_NACK);
        twi_stop();

        // Send values to UART
        rtc.hours = rtc.hours & 0x1f;  // Filter Hours
        itoa(rtc.hours, string, 16);
        uart_puts(string);
        uart_puts(":");
        itoa(rtc.mins, string, 16);
        uart_puts(string);
        uart_puts(":");
        itoa(rtc.secs, string, 16);
        uart_puts(string);
        uart_puts("\t");
    }
*/
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
}

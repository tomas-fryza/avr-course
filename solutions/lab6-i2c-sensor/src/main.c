/***********************************************************************
 * 
 * Communication via I2C (TWI) bus with temperature/humidity sensor.
 * Read values every 5 sec and send them to UART.
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

// Slave and internal addresses of temperature/humidity sensor DHT12
#define SENSOR_ADR 0x5c
#define SENSOR_HUM_MEM 0
#define SENSOR_TEMP_MEM 2
#define SENSOR_CHECKSUM 4

#define RTC_ADR 0x68
#define RTC_SEC_MEM 0


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
    uint8_t hum_int;
    uint8_t hum_dec;
    uint8_t temp_int;
    uint8_t temp_dec;
    uint8_t checksum;
} dht12;

// Flag for printing new data from sensor
volatile uint8_t new_sensor_data = 0;


/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Wait for new data from the sensor and sent them to UART.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    char string[2];  // String for converting numbers by itoa()

    // TWI
    twi_init();

    // UART
    uart_init(UART_BAUD_SELECT(115200, F_CPU));

    sei();  // Needed for UART

    // Test if sensor is ready
    if (twi_test_address(SENSOR_ADR) == 0)
        uart_puts("I2C sensor detected\r\n");
    else {
        uart_puts("[ERROR] I2C device not detected\r\n");
        while (1);
    }

    // Timer1
    TIM1_ovf_1sec();
    TIM1_ovf_enable();

    // Infinite loop
    while (1) {
        if (new_sensor_data == 1) {
            // Display temperature
            itoa(dht12.temp_int, string, 10);
            uart_puts(string);
            uart_puts(".");
            itoa(dht12.temp_dec, string, 10);
            uart_puts(string);
            uart_puts(" °C\t\t");

            // Display humidity
            itoa(dht12.hum_int, string, 10);
            uart_puts(string);
            uart_puts(".");
            itoa(dht12.hum_dec, string, 10);
            uart_puts(string);
            uart_puts(" \%\t\t");

            // Display checksum
            itoa(dht12.checksum, string, 16);
            uart_puts(string);
            uart_puts("\r\n");

            // Do not print it again and wait for the new data
            new_sensor_data = 0;
        }
    }

    // Will never reach this
    return 0;
}


/* Interrupt service routines ----------------------------------------*/
/**********************************************************************
 * Function: Timer/Counter1 overflow interrupt
 * Purpose:  Read temperature and humidity from DHT12, SLA = 0x5c.
 **********************************************************************/
ISR(TIMER1_OVF_vect)
{
    static uint8_t n_ovfs = 0;

    n_ovfs++;
    // Read the data every 5 secs
    if (n_ovfs >= 5) {
        n_ovfs = 0;

        // Read values from Temp/Humid sensor
        twi_start();
        if (twi_write((SENSOR_ADR<<1) | TWI_WRITE) == 0) {
            // Set internal memory location
            twi_write(SENSOR_HUM_MEM);
            twi_stop();

            // Read data from internal memory
            twi_start();
            twi_write((SENSOR_ADR<<1) | TWI_READ);
            dht12.hum_int = twi_read(TWI_ACK);
            dht12.hum_dec = twi_read(TWI_ACK);
            dht12.temp_int = twi_read(TWI_ACK);
            dht12.temp_dec = twi_read(TWI_ACK);
            dht12.checksum = twi_read(TWI_NACK);
            twi_stop();

            new_sensor_data = 1;
        }
        else {
            twi_stop();
        }
    }
}



/*
// Declaration of "rtc" variable with structure "RTC_values_structure"
struct RTC_values_structure {
    uint8_t secs;
    uint8_t mins;
    uint8_t hours;
} rtc;


            // Display RTC data
            itoa(rtc.mins, string, 16);
            uart_puts(string);
            uart_puts(".");
            itoa(rtc.secs, string, 16);
            uart_puts(string);
            uart_puts(":\t");


    // Read Time from RTC DS3231; SLA = 0x68
    // FYI: MPU-6050; SLA = 0x68
        // Test ACK from RTC
        twi_start();
        if (twi_write((RTC_ADR<<1) | TWI_WRITE) == 0) {
            // Set internal memory location
            twi_write(RTC_SEC_MEM);
            twi_stop();
            // Read data from internal memory
            twi_start();
            twi_write((RTC_ADR<<1) | TWI_READ);
            rtc.secs = twi_read(TWI_ACK);
            rtc.mins = twi_read(TWI_ACK);
            rtc.hours = twi_read(TWI_NACK);

        }
        twi_stop();
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



/*
    // MPU-6050 reset
    // twi_start();
    // twi_write((0x68<<1) | TWI_WRITE);
    // twi_write(0x6b);
    // twi_write(0x00);
    // twi_stop();
*/

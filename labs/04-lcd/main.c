/***********************************************************************
 * 
 * Stopwatch by Timer/Counter2 on the Liquid Crystal Display (LCD).
 *
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 *
 * Copyright (c) 2017 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 * Components list:
 *   16x2 character LCD with parallel interface
 *     VSS  - GND (Power supply ground)
 *     VDD  - +5V (Positive power supply)
 *     Vo   - (Contrast)
 *     RS   - PB0 (Register Select: High for Data transfer, Low for Instruction transfer)
 *     RW   - GND (Read/Write signal: High for Read mode, Low for Write mode)
 *     E    - PB1 (Read/Write Enable: High for Read, falling edge writes data to LCD)
 *     D3:0 - NC (Data bits 3..0, Not Connected)
 *     D4   - PD4 (Data bit 4)
 *     D5   - PD5 (Data bit 5)
 *     D6   - PD6 (Data bit 6)
 *     D7   - PD7 (Data bit 7)
 *     A+K  - Back-light enabled/disabled by PB2
 * 
 **********************************************************************/


/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include <gpio.h>           // GPIO library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include <lcd.h>            // Peter Fleury's LCD library
#include <stdlib.h>         // C library. Needed for number conversions


/* Global variables --------------------------------------------------*/
// Flag for printing new stopwatch data to LCD
volatile uint8_t update_lcd_stopwatch = 0;

// Stopwatch values
// Declaration of "stopwatch" variable with structure "Stopwatch_structure"
struct Stopwatch_structure {
    uint8_t tenths;  // Tenths of a second
    uint8_t secs;    // Seconds
    uint8_t mins;    // Minutes
} stopwatch;


/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Update stopwatch value on LCD screen when 8-bit 
 *           Timer/Counter2 overflows.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    char string[2];  // String for converted numbers by itoa()

    // Initialize display
    lcd_init(LCD_DISP_ON_CURSOR_BLINK);

    // Put string(s) on LCD screen
    lcd_gotoxy(6, 1);
    lcd_puts("LCD Test");
    lcd_putc('!');

    // Configuration of 8-bit Timer/Counter2 for Stopwatch update
    // Set the overflow prescaler to 16 ms and enable interrupt

    // WRITE YOUR CODE HERE

    // Enables interrupts by setting the global interrupt mask
    sei();

    // Infinite loop
    while (1) {
        if (update_lcd_stopwatch == 1) {

            itoa(stopwatch.tenths, string, 10);  // Convert decimal value to string
            // Display "00:00.tenths"
            lcd_gotoxy(7, 0);
            lcd_puts(string);

            // WRITE YOUR CODE HERE

            update_lcd_stopwatch = 0;
        }
    }

    // Will never reach this
    return 0;
}


/* Interrupt service routines ----------------------------------------*/
/**********************************************************************
 * Function: Timer/Counter2 overflow interrupt
 * Purpose:  Update the stopwatch on LCD screen every sixth overflow,
 *           ie approximately every 100 ms (6 x 16 ms = 100 ms).
 **********************************************************************/
ISR(TIMER2_OVF_vect)
{
    static uint8_t n_ovfs = 0;

    n_ovfs++;
    if (n_ovfs >= 6) {
        // Do this every 6 x 16 ms = 100 ms
        n_ovfs = 0;

        // Count tenth of seconds 0, 1, ..., 9, 0, 1, ...
        stopwatch.tenths++;

        // WRITE YOUR CODE HERE

        update_lcd_stopwatch = 1;
    }
    // Else do nothing and exit the ISR
}

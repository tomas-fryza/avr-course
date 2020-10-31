/***********************************************************************
 * 
 * Stopwatch with LCD display output.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2017-2020 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include "lcd.h"            // Peter Fleury's LCD library
#include <stdlib.h>         // C library. Needed for conversion function

/* Function definitions ----------------------------------------------*/
/**
 * Main function where the program execution begins. Display stopwatch
 * values on LCD display when 16-bit Timer/Counter2 overflows.
 */
int main(void)
{
    // Inicialize LCD display
    lcd_init(LCD_DISP_ON_CURSOR_BLINK);

    // Test of LCD display: put string from position (1,0)
    lcd_gotoxy(1, 0);
    lcd_puts("LCD Test");
    lcd_putc('!');

    /* Configure 16-bit Timer/Counter2
     * Set prescaler and enable overflow interrupt */

    // Enables interrupts by setting the global interrupt mask
    sei();

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
/**
 * ISR starts when Timer/Counter2 overflows. Update stopwatch value on
 * LCD display.
 */
ISR(TIMER2_OVF_vect)
{
    // WRITE YOUR CODE HERE
}

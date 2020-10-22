/***********************************************************************
 * 
 * Decimal counter with LCD display output.
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
 * Main function where the program execution begins. Display decimal 
 * counter values on LCD display when 16-bit Timer/Counter1 overflows.
 */
int main(void)
{
    // Inicialize LCD display
    lcd_init(LCD_DISP_ON_CURSOR_BLINK);

    // Test of LCD display: put string at position (3,0)
    lcd_gotoxy(3, 0);
    lcd_puts("LCD");

    /* Configure 16-bit Timer/Counter1
     * Set prescaler and enable overflow interrupt */

    // Enables interrupts by setting the global interrupt mask

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
 * ISR starts when Timer/Counter1 overflows. Increment decimal counter
 * value and display it on LCD display.
 */
ISR(TIMER1_OVF_vect)
{
    // WRITE YOUR CODE HERE
}

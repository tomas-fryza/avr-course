/***********************************************************************
 * 
 * Implementation of LFSR-based (Linear Feedback Shift Register) 
 * pseudo-random generator in AVR assembly.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2017-2021 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/

/* Defines -----------------------------------------------------------*/
#ifndef F_CPU
# define F_CPU 16000000
#endif

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include <stdlib.h>         // C library. Needed for conversion function
#include "uart.h"           // Peter Fleury's UART library

/* Function prototypes -----------------------------------------------*/
uint8_t rand4_asm(uint8_t value);
uint8_t rand8_asm(uint8_t value);

/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Use Timer/Counter1 and generate pseudo-random values 
 *           using 4- and 8-bit LFSR structure.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    // Set all pins from port B as output
    DDRB = 0xff;
    // Set all pins from port B to low
    PORTB = 0x00;

    // Initialize UART to asynchronous, 8N1, 9600
    uart_init(UART_BAUD_SELECT(9600, F_CPU));

    // Configure 16-bit Timer/Counter1 to update FSM
    // Enable interrupt and set the overflow prescaler to 262 ms
    TIM1_overflow_262ms();
    TIM1_overflow_interrupt_enable();

    // Enables interrupts by setting the global interrupt mask
    sei();

    // Put strings to ringbuffer for transmitting via UART
    uart_puts("LFSR-based pseudo-random generator:\r\n");

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
 * Purpose:  Update Finite State Machine and generate 4- and 8-bit 
             pseudo-random sequences.
 **********************************************************************/
ISR(TIMER1_OVF_vect)
{
    // Type of LFSR structure (0 @ 4-bit, 1 @ 8-bit, 2 @ nothing)
    static uint8_t type = 0;
    static uint8_t value = 0;
    static uint8_t number_of_values = 0;
    // String for converting numbers by itoa()
    char uart_string[8] = "00000000";

    // If TYPE is 0 then generate a 4-bit sequence
    if (type == 0)
    {
        // Transmit LFSR value via UART in hexadecimal, binary, and decimal

        // Display LFSR value by LEDs

        // Generate one LFSR value
        value = rand4_asm(value);

        // Increment number of generated LFSR values
        number_of_values++;

        // If VALUE is equal to 0 then print length info and change LFSR type
        if (value == 0)
        {
            uart_puts("Length of sequence: ");
            // Print length of generated sequence

            // Change LFSR type and reset values
            type++;
            value = 0;
            number_of_values = 0;
        }
    }
}

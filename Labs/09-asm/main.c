/***********************************************************************
 * 
 * Implementation of LFSR-based (Linear Feedback Shift Register) 
 * pseudo-random generator in AVR assembly.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2017-2020 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/

/* Defines -----------------------------------------------------------*/
#ifndef F_CPU
#define F_CPU 16000000
#endif

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include <stdlib.h>         // C library. Needed for conversion function
#include "uart.h"           // Peter Fleury's UART library

/* Variables ---------------------------------------------------------*/
typedef enum {              // FSM declaration
    STATE_IDLE = 1,
    STATE_RAND4,
    STATE_RAND8,
    STATE_INFO
} state_t;

/* Function prototypes -----------------------------------------------*/
extern uint8_t rand4_asm(uint8_t value);
extern uint8_t rand8_asm(uint8_t value);

/* Function definitions ----------------------------------------------*/
/**
 * Main function where the program execution begins. Use Timer/Counter1
 * and generate pseudo-random values using 4- and 8-bit LFSR structure.
 */
int main(void)
{
    // Set all pins from port B as output

    // Set all pins from port B to low

    // Initialize UART to asynchronous, 8N1, 9600
    uart_init(UART_BAUD_SELECT(9600, F_CPU));

    // Configure 16-bit Timer/Counter1 to update FSM
    // Enable interrupt and set the overflow prescaler to 262 ms
    TIM1_overflow_262ms();
    TIM1_overflow_interrupt_enable();

    // Enables interrupts by setting the global interrupt mask
    sei();

    // Put strings to ringbuffer for transmitting via UART
    uart_puts("\r\nLFSR-based pseudo-random generator:");

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
 * ISR starts when Timer/Counter1 overflows. Update Finite State Machine
 * and test generate 4- and 8-bit pseudo-random sequences.
 */
ISR(TIMER1_OVF_vect)
{
    static state_t state = STATE_IDLE;  // Current state of the FSM
    // Type of LFSR structure (0 @ 4-bit, 1 @ 8-bit, 2 @ nothing)
    static uint8_t lfsr_type = 0;
    static uint8_t lfsr_value = 0;
    static uint8_t number_of_values = 0;
    char uart_string[8] = "00000000";   // String for converting numbers by itoa()

    // FSM
    switch (state)
    {
    // Select type of LFSR structure
    case STATE_IDLE:
        // If type is 0 then start 4-bit generator
        if (lfsr_type == 0)
        {
            // Reset variables lfsr_value and number_of_values

            // Move to RAND4 state
            state = STATE_RAND4;
        }
        // If type is 1 then start 8-bit generator
        else if (lfsr_type == 1)
        {
            // Reset variables lfsr_value and number_of_values

            // Move to RAND4 state

        }
        // If type is 2 then do nothing
        else
            // Do nothing
        break;

    // Generate 4-bit LFSR sequence
    case STATE_RAND4:
        // Generate one LFSR value and move to INFO state
        lfsr_value = rand4_asm(lfsr_value);
        state = STATE_INFO;
        break;

    // Generate 8-bit LFSR sequence
    case STATE_RAND8:
        // Generate one LFSR value and move to INFO state
        lfsr_value = rand8_asm(lfsr_value);
        state = STATE_INFO;
        break;

    // Print information about LFSR values
    case STATE_INFO:
        // Transmit LFSR value via UART in hexadecimal, binary, and decimal

        // Display LFSR value by LEDs

        // If LFSR value is equal to 0 then print length info and move to IDLE
        if (lfsr_value == 0)
        {
            uart_puts("Length of sequence: ");
            // Print length of generated sequence

            // Change LFSR type and move to IDLE state
            lfsr_type++;
            state = STATE_IDLE;
        }
        else
        {
            // Increment number of generated LFSR values
            number_of_values++;
            if (lfsr_type == 0)
                state = STATE_RAND4;
            else
                state = STATE_RAND8;
        }
        break;

    // If something unexpected happens then move to IDLE
    default:
        state = STATE_IDLE;
        break;
    }
}

/***********************************************************************
 * 
 * Implementation of LFSR-based (Linear Feedback Shift Register) 
 * pseudo-random generator in AVR assembly.
 * 
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 *
 * Copyright (c) 2017 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 * NOTE:
 *   To see assembly listing, run the following command in Terminal
 *   after the compilation.
 * 
 *   Windows:
 *   C:\Users\YOUR-LOGIN\.platformio\packages\toolchain-atmelavr\bin\avr-objdump -S -d -m avr .pio/build/uno/firmware.elf > firmware.lst
 * 
 *   Linux:
 *   ~/.platformio/packages/toolchain-atmelavr/bin/avr-objdump -S -d -m avr .pio/build/uno/firmware.elf > firmware.lst
 * 
 * SEE ALSO:
 *   https://five-embeddev.com/baremetal/platformio/
 *
 **********************************************************************/


// Settings for main page of Doxygen manual
/**
 * @mainpage
 * 
 * Collection of AVR libraries used in bachelor course Digital 
 * Electronics 2 at Brno University of Technology, Czechia.
 * 
 * @author Tomas Fryza, Peter Fleury
 * @copyright (c) 2018 Tomas Fryza, This work is licensed under 
 *                the terms of the MIT license
 */


/* Defines -----------------------------------------------------------*/
#ifndef F_CPU
# define F_CPU 16000000  // CPU frequency in Hz required for UART_BAUD_SELECT
#endif


/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include <uart.h>           // Peter Fleury's UART library
#include <stdlib.h>         // C library. Needed for number conversions


// Goxygen module with assembly functions starts here
/**
 * @defgroup fryza_asm Assembly functions
 * @brief Function(s) written in AVR Assembly language.
 * @{
 */

/* Function prototypes -----------------------------------------------*/
/**
 * @brief  Multiply-and-Accumulate operation, ie. result = result + (a*b).
 * @param  result Current MAC value
 * @param  a Value A
 * @param  b Value B
 * @return New MAC result
 * @note   Function programmed in AVR assembly language.
 */
uint8_t multiply_accumulate_asm(uint8_t result, uint8_t a, uint8_t b);

/**
 * @brief  LFSR-based 4-bit pseudo-random generator with Fibonacci
 *         architecture. Taps are 4, 3.
 * @param  value Current value of LFSR
 * @return New value of LFSR
 * @note   Function programmed in AVR assembly language.
 */
uint8_t lfsr4_fibonacci_asm(uint8_t value);

// Goxygen module with assembly functions ends here
/** @} */


/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Use Timer/Counter1 and generate a new pseudo-random value 
 *           using 4- and/or 8-bit LFSR structure every 1 sec. Send 
 *           information about LFSR process to UART.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    // Initialize USART to asynchronous, 8-N-1, 115200
    // NOTE: Add `monitor_speed = 115200` to `platformio.ini`
    uart_init(UART_BAUD_SELECT(115200, F_CPU));

    // Configure 16-bit Timer/Counter1 to generate one LFSR state
    // Set prescaler to 1 sec and enable interrupt
    TIM1_OVF_1SEC
    TIM1_OVF_ENABLE

    // Enables interrupts by setting the global interrupt mask
    sei();

    // Put strings to ringbuffer for transmitting via UART
    uart_puts("LFSR-based pseudo-random generator:\r\n");

    // Infinite loop
    while (1) {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines ISRs */
    }

    // Will never reach this
    return 0;
}


/* Interrupt service routines ----------------------------------------*/
/**********************************************************************
 * Function: Timer/Counter1 overflow interrupt
 * Purpose:  Generate one pseudo-random value using 4- and/or 8-bit
 *           LFSR structure.
 *
 * Note: (4,3): 0, 1, 3, 7, 14, 13, 11, 6, 12, 9, 2, 5, 10, 4, 8
 *       (4,2): 0, 1, 3, 6, 12, 8
 *       (4,1): 0, 1, 2, 5, 10, 4, 9, 3, 6, 13, 11, 7, 14, 12, 8
 **********************************************************************/
ISR(TIMER1_OVF_vect)
{
    static uint8_t value = 0;  // Initial value
    char string[3];            // String for converting numbers by itoa()

    // Multiply-and-accumulate Assembly example
    value = multiply_accumulate_asm(value, 2, 3);

    // Send new `value` to UART

    // WRITE YOUR CODE HERE

}



/*
    // Multiply-and-accumulate Assembly example
    value = multiply_accumulate_asm(value, 2, 3);
    // Display new `value`
    itoa(value, string, 10);
    uart_puts(string);
    uart_puts("\r\n");
*/

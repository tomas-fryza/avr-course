/***********************************************************************
 * 
 * Implementation of LFSR-based (Linear Feedback Shift Register) 
 * pseudo-random generator in AVR assembly.
 * (c) 2017-2024 Tomas Fryza, MIT license
 *
 * Developed using PlatformIO and AVR 8-bit Toolchain 3.6.2.
 * Tested on Arduino Uno board and ATmega328P, 16 MHz.
 * 
 * NOTE:
 *   To see assembly listing, run the following command in Terminal
 *   after the compilation.
 * 
 *   Windows:
 *   C:\Users\YOUR-LOGIN\.platformio\packages\toolchain-atmelavr\bin\avr-objdump -S -d -m avr .pio/build/uno/firmware.elf > firmware.lst
 * 
 *   Linux, Mac:
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
 * @copyright (c) 2017-2024 Tomas Fryza, MIT license
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


/* Function prototypes -----------------------------------------------*/
// Goxygen module with assembly functions starts here
/**
 * @defgroup fryza_asm Assembly functions
 * @brief Function(s) written in AVR Assembly language.
 * @{
 */

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

    // Configure 16-bit Timer/Counter1
    TIM1_ovf_1sec();
    TIM1_ovf_enable();

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
    static uint8_t n_vals = 0;
    static uint8_t value = 0;
    char string[3];  // String for converting numbers by itoa()

    // Multiply-and-accumulate Assembly example
    //                                 c + (a*b)
    // value = multiply_accumulate_asm(value, 3, 7);

    // Send value to UART
    itoa(value, string, 10);
    uart_puts(string);
    uart_puts(", ");

    // WRITE YOUR CODE HERE
    // LFSR 4-bit counter
    value = lfsr4_fibonacci_asm(value);
    n_vals++;
    if (value == 0)
    {
        uart_puts("Length = ");
        itoa(n_vals, string, 10);
        uart_puts(string);
        uart_puts("\r\n");
        n_vals = 0;
    }
}

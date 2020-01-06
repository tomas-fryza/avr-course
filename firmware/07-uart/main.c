/***********************************************************************
 * 
 * Analog-to-digital conversion with displaying result on LCD and 
 * transmitting via UART.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2018-2019 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/

/* Includes ----------------------------------------------------------*/
#include <stdlib.h>         // itoa() function
#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"
#include "uart.h"

/* Typedef -----------------------------------------------------------*/
/* Define ------------------------------------------------------------*/
#define UART_BAUD_RATE 9600

/* Variables ---------------------------------------------------------*/
/* Function prototypes -----------------------------------------------*/

/* Functions ---------------------------------------------------------*/
/* Main --------------------------------------------------------------*/
/* Read ADC result and transmit via UART. */
int main(void) {

    /* ADC
     * TODO: Configure ADC reference, clock source, enable ADC module, 
     *       and enable conversion complete interrupt */

    /* Timer1
     * TODO: Configure Timer1 clock source and enable overflow 
     *       interrupt */

    // UART: asynchronous, 8-bit data, no parity, 1-bit stop
    uart_init(UART_BAUD_SELECT(UART_BAUD_RATE, F_CPU));

    // Enables interrupts by setting the global interrupt mask
    sei();

    // Put string to ringbuffer for transmitting via UART.
    uart_puts("UART testing\r\n");

    // Infinite loop
    for (;;) {
    }

    // Will never reach this
    return 0;
}

/* Interrupts --------------------------------------------------------*/
/* Timer1 overflow interrupt routine.
 * Start ADC conversion. */
ISR(TIMER1_OVF_vect) {

    // TODO: Start ADC conversion
}

/* -------------------------------------------------------------------*/
/* ADC complete interrupt routine.
 * Update LCD and UART transmiter. */
ISR(ADC_vect) {

//    uint16_t value = 0;
//    char uart_string[4];

	// Read 10-bit ACD value
//    value = ADC;

    // TODO: Update LCD and UART transmiter
}

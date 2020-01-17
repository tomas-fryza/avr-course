/***********************************************************************
 * 
 * Control LED(s) using Pin Change Interrupts.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2018-2019 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>
#include <avr/interrupt.h>
#include "gpio.h"
//#include "timer.h"
//#include "segment.h"

/* Typedef -----------------------------------------------------------*/
/* Define ------------------------------------------------------------*/
#define LED_D1  PB5
#define BTN_S1  PC1     // PCINT 9
#define BTN_S2  PC2     // PCINT 10
#define BTN_S3  PC3     // PCINT 11

/* Variables ---------------------------------------------------------*/
/* Function prototypes -----------------------------------------------*/

/* Functions ---------------------------------------------------------*/
/* Main --------------------------------------------------------------*/
/* Toggle LED(s) using push buttons and Pin Chang Interrupts. */
int main(void) {

    // TODO: Configure LED_D1
    // TODO: Configure Pin Change Interrupts number 11, 10, and 9

    // TODO: Configure 7-segment display pins

    // Enable interrupts by setting the global interrupt mask
    sei();

    // Infinite loop
    for (;;) {
        // TODO: Use function to display digit "3" at position 0
        //SEG_putc(3, 0);
    }

    // Will never reach this
    return 0;
}

/* Interrupts --------------------------------------------------------*/
/* Pin Change Interrupt 11:9 routine.
 * Toggle a LED(s). */
/*ISR(???) {

    // TODO: Toggle LED(s)
}
*/

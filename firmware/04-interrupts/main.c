/***********************************************************************
 * 
 * Control LEDs using functions from GPIO and Timer libraries. Do not 
 * use delay library any more.
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
#include "timer.h"

/* Typedef -----------------------------------------------------------*/
/* Define ------------------------------------------------------------*/
#define LED_GREEN   PB5
#define LED_BLUE    PB3
#define LED_RED     PB0

/* Variables ---------------------------------------------------------*/
/* Function prototypes -----------------------------------------------*/

/* Functions ---------------------------------------------------------*/
/* Main --------------------------------------------------------------*/
/* Toggle three LEDs with internal 8- and 16-bit timer modules. */
int main(void) {

    // LED_GREEN
    GPIO_output(&DDRB, LED_GREEN);
    GPIO_write(&PORTB, LED_GREEN, LOW);
    /* LED_BLUE
     * TODO: Configure blue LED */

    /* LED_RED
     * TODO: Configure red LED */

    /* Set Timer0
     * TODO: Configure Timer0 clock source and enable overflow 
     *       interrupt */

    /* Set Timer1
     * Configure Timer1 clock source and enable overflow interrupt */
    TIM1_overflow_262ms();
    TIM1_overflow_enable();

    /* Set Timer2
     * TODO: Configure Timer2 clock source and enable overflow 
     *       interrupt */

    // Enables interrupts by setting the global interrupt mask
    sei();

    // Infinite loop
    for (;;) {
    }

    // Will never reach this
    return 0;
}

/* Interrupts --------------------------------------------------------*/
/* Timer/Counter0 overflow interrupt routine.
 * Toggle green LED. */
/*ISR(TIMER0_OVF_vect) {

    // TODO: Toggle green LED
}
*/
/* -------------------------------------------------------------------*/
/* Timer/Counter1 overflow interrupt routine.
 * Toggle blue LED. */
ISR(TIMER1_OVF_vect) {

    // TODO: Toggle blue LED
}

/* -------------------------------------------------------------------*/
/* Timer/Counter2 overflow interrupt routine.
 * Toggle red LED. */
/*ISR(TIMER2_OVF_vect) {

    // TODO: Toggle red LED
}
*/

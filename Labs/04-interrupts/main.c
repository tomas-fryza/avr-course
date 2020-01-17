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
#define LED_D1  PB5
#define LED_D2  PB4
#define LED_D3  PB3

/* Variables ---------------------------------------------------------*/
/* Function prototypes -----------------------------------------------*/

/* Functions ---------------------------------------------------------*/
/* Main --------------------------------------------------------------*/
/* Toggle three LEDs with internal 8- and 16-bit timer modules. */
int main(void) {

    // TODO: Configure LED_D1
    // Configure LED_D2
    GPIO_output(&DDRB, LED_D2);
    GPIO_write(&PORTB, LED_D2, LOW);
    // TODO: Configure LED_D3

    // TODO: Configure Timer0 clock and enable overflow interrupt
    // Configure Timer1 clock and enable overflow interrupt
    TIM1_overflow_262ms();
    TIM1_overflow_enable();
    // TODO: Configure Timer2 clock and enable overflow interrupt

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
 * Toggle LED_D1. */
/*ISR(TIMER0_OVF_vect) {

    // TODO: Toggle LED_D1
}
*/
/* -------------------------------------------------------------------*/
/* Timer/Counter1 overflow interrupt routine.
 * Toggle LED_D2. */
ISR(TIMER1_OVF_vect) {

    // TODO: Toggle LED_D2
}

/* -------------------------------------------------------------------*/
/* Timer/Counter2 overflow interrupt routine.
 * Toggle LED_D3. */
/*ISR(TIMER2_OVF_vect) {

    // TODO: Toggle LED_D3
}
*/

/***********************************************************************
 * 
 * Control LEDs using functions from GPIO library.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2019 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>
#include <util/delay.h>
#include "gpio.h"

/* Typedef -----------------------------------------------------------*/
/* Define ------------------------------------------------------------*/
#define LED_GREEN   PB5
#define LED_RED     PB0
#define BTN_BLUE    PD2
#define BLINK_DELAY 500

/* Variables ---------------------------------------------------------*/
/* Function prototypes -----------------------------------------------*/

/* Functions ---------------------------------------------------------*/
/* Main --------------------------------------------------------------*/
/* Toggle two LEDs with the push button. */
int main(void) {

    // Set output pins of two LEDs to low level
    // LED_GREEN
    GPIO_output(&DDRB, LED_GREEN);
    GPIO_write(&PORTB, LED_GREEN, LOW);
    // LED_RED

    /* Configure input pin of push button and enable internal pull-up
       resistor */

    // Infinite loop
    for (;;) {
        // Test if push button value is low
            // Invert LED and delay
            _delay_ms(BLINK_DELAY);
    }

    // Will never reach this
    return 0;
}

/* Interrupts --------------------------------------------------------*/

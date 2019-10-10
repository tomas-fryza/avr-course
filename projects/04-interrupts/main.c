/*
 * ---------------------------------------------------------------------
 * Author:      Tomas Fryza
 *              Dept. of Radio Electronics, Brno Univ. of Technology
 * Created:     2019-09-26
 * Last update: 2019-10-04
 * Platform:    ATmega328P, AVR 8-bit Toolchain 3.6.2
 * ---------------------------------------------------------------------
 * Description: Control LEDs using functions from GPIO library.
 * TODO: Create and test functions to control GPIO pin.
 * NOTE: Store gpio.c and gpio.h files in library/src and library/inc
 *       folders.
 */

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
/**
  * Brief:  Main program. Blink two LEDs with a push button.
  * Input:  None
  * Return: None
  */
int main(void)
{
    /* Set output pins of two LEDs to low level */
    /* LED_GREEN */
    GPIO_config_output(&DDRB, LED_GREEN);
    GPIO_write(&PORTB, LED_GREEN, PIN_LOW);
    /* LED_RED */

    /* Configure input pin of push button and enable internal pull-up
       resistor */

    /* Infinite loop */
    for (;;) {
        /* Test if push button value is low */
            /* Invert LED and delay */
            _delay_ms(BLINK_DELAY);
    }

    return (0);
}

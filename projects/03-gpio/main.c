/*
 * ---------------------------------------------------------------------
 * Author:      Tomas Fryza
 *              Dept. of Radio Electronics, Brno Univ. of Technology
 * Created:     2019-09-26
 * Last update: 2019-xx-xx
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

/* Typedef -----------------------------------------------------------*/
/* Define ------------------------------------------------------------*/
#define LED_GREEN   PB5
#define BLINK_DELAY 250

/* Variables ---------------------------------------------------------*/
/* Function prototypes -----------------------------------------------*/

/* Functions ---------------------------------------------------------*/
/**
  * Brief:  Main program. Blink LEDs with delay function.
  * Input:  None
  * Return: None
  */
int main(void)
{
    /* Set output pin to low level*/
    GPIO_init_pin(PORTB, LED_GREEN, OUTPUT);
    GPIO_write_pin(PORTB, LED_GREEN, PIN_RESET);

    /* Infinite loop */
    for (;;)
    {
        /* Invert LED and delay */
        GPIO_toggle_pin(PORTB, LED_GREEN);
        _delay_ms(BLINK_DELAY);     /* Wait for several milisecs */
    }

    return (0);
}

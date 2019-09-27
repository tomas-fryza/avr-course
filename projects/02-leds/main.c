/*
 * ---------------------------------------------------------------------
 * Author:      Tomas Fryza
 *              Dept. of Radio Electronics, Brno Univ. of Technology
 * Created:     2018-11-28
 * Last update: 2019-09-27
 * Platform:    ATmega328P, AVR 8-bit Toolchain 3.6.2
 * ---------------------------------------------------------------------
 * Description: Alternately switch two LEDs with a push button.
 * TODO: On a breadboard, connect push button and second LED 
 *       including the corresponding resistor.
 * NOTE: Use internal pull-up resistor for push button.
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
  * Brief:  Main program. Blink two LEDs with a push button.
  * Input:  None
  * Return: None
  */
int main(void)
{
    /* Set output pin to low level */
    DDRB |= _BV(LED_GREEN);         /* or: Set to 1 */
    PORTB &= ~_BV(LED_GREEN);       /* and: Clear to 0 */

    /* Infinite loop */
    for (;;)
    {
        /* Invert LED and delay */
        PORTB ^= _BV(LED_GREEN);    /* xor: Invert bit */
        _delay_ms(BLINK_DELAY);     /* Wait for several milisecs */
    }

    return (0);
}

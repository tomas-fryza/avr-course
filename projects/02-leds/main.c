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
    /* Set output pins to low level */
    DDRB |= _BV(LED_GREEN);         /* or: Set to 1 */
    DDRB |= _BV(LED_RED);
    PORTB &= ~_BV(LED_GREEN);       /* and: Clear to 0 */
    PORTB &= ~_BV(LED_RED);

    /* Activate internal pull-up resistor */
    DDRD &= ~_BV(BTN_BLUE);
    PORTD |= _BV(BTN_BLUE);

    /* Infinite loop */
    for (;;)
    {
        if (bit_is_clear(PIND, BTN_BLUE)) {
            /* Invert LED and delay */
            PORTB ^= _BV(LED_GREEN);    /* xor: Invert bit */
            PORTB ^= _BV(LED_RED);
            _delay_ms(BLINK_DELAY);     /* Wait for several milisecs */
        }
    }

    return (0);
}

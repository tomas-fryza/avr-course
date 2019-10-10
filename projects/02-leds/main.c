/*
 * ---------------------------------------------------------------------
 * Author:      Tomas Fryza
 *              Dept. of Radio Electronics, Brno Univ. of Technology
 * Created:     2018-11-28
 * Last update: 2019-10-02
 * Platform:    ATmega328P, AVR 8-bit Toolchain 3.6.2
 * ---------------------------------------------------------------------
 * Description: Alternately toggle two LEDs with the push button.
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
 *  Brief:  Main program. Toggle two LEDs with the push button.
 *  Input:  None
 *  Return: None
 */
int main(void)
{
    /* Set output pins of two LEDs to low level */
    /* LED_GREEN */
    DDRB = DDRB | _BV(LED_GREEN);       /* or: Set bit to 1 */
    PORTB = PORTB & ~_BV(LED_GREEN);    /* and: Clear bit to 0 */
    /* LED_RED */
    DDRB = DDRB | _BV(LED_RED);
    PORTB = PORTB & ~_BV(LED_RED);

    /* Configure input pin of push button and enable internal pull-up
       resistor */
    DDRD = DDRD & ~_BV(BTN_BLUE);       /* DDRD2 = 0 */
    PORTD = PORTD | _BV(BTN_BLUE);      /* PORTD2 = 1 */

    /* Infinite loop */
    for (;;) {
        /* Test if push button value is low */
        if (bit_is_clear(PIND, BTN_BLUE)) {
            /* Invert LED and delay */
            PORTB = PORTB ^ _BV(LED_GREEN); /* xor: Invert bit */
            PORTB = PORTB ^ _BV(LED_RED);
            _delay_ms(BLINK_DELAY);
        }
    }

    return (0);
}

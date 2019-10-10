/*
 * ---------------------------------------------------------------------
 * Author:      Tomas Fryza
 *              Dept. of Radio Electronics, Brno Univ. of Technology
 * Created:     2018-09-27
 * Last update: 2019-10-04
 * Platform:    ATmega328P, AVR 8-bit Toolchain 3.6.2
 * ---------------------------------------------------------------------
 * Description: Blink a LED with the delay function.
 * TODO: Verify functionality of LED blinker.
 * NOTE: Macro _BV converts a bit number into a byte value (see AVR Libc
 *       Reference Manual).
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
 *  Brief:  Main program. Toggle a LED with the delay function.
 *  Input:  None
 *  Return: None
 */
int main(void)
{
    /* Set output pin */
    DDRB = DDRB | _BV(LED_GREEN);       /* DDRB OR 0010 0000 */

    /* Set pin low, ie turn LED off */
    PORTB = PORTB & ~_BV(LED_GREEN);    /* PORTB AND 1101 1111 */

    /* Infinite loop */
    for (;;) {
        /* Invert LED and delay */
        PORTB = PORTB ^ _BV(LED_GREEN); /* PORTB XOR 0010 0000 */
        _delay_ms(BLINK_DELAY);         /* Wait for several milisecs */
    }

    return (0);
}

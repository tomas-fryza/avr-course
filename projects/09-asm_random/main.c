/*
 * ---------------------------------------------------------------------
 * Author:      Tomas Fryza
 *              Dept. of Radio Electronics, Brno Univ. of Technology
 * Created:     2017-11-09
 * Last update: 2019-11-16
 * Platform:    ATmega328P, 16 MHz, AVR 8-bit Toolchain 3.6.2
 * ---------------------------------------------------------------------
 * Description:
 *    Implementation of LFSR-based (Linear Feedback Shift Register) 
 *    pseudo-random generator in AVR assembly.
 */

/* Includes ----------------------------------------------------------*/
#include <stdlib.h>         // itoa() function
#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"
#include "uart.h"

/* Typedef -----------------------------------------------------------*/
typedef enum {
    IDLE_STATE = 1,
    RAND4_STATE,
    RAND8_STATE,
    UART_STATE
} state_t;

/* Define ------------------------------------------------------------*/
#define UART_BAUD_RATE 9600

/* Variables ---------------------------------------------------------*/
state_t current_state = IDLE_STATE;

/* Function prototypes -----------------------------------------------*/
void fsm_random(void);
extern uint8_t rand4_asm(uint8_t current);
extern uint8_t rand8_asm(uint8_t current);

/* Functions ---------------------------------------------------------*/
/**
 *  Brief:  Main program. Generate a sequence of LFSR preudo-random 
 *          values using 4- and 8-bit structure.
 */
int main(void)
{
    uart_init(UART_BAUD_SELECT(UART_BAUD_RATE, F_CPU)); // 8N1

    /* Timer1
     * TODO: Enable overflow interrupt every 33 msec. */

    sei();
    uart_puts("\r\n---LFSR pseudo-random generator---\r\n");

    for (;;) {
    }

    return (0);
}

/**
 *  Brief: Timer1 overflow interrupt routine. Update state of the FSM.
 */
ISR(TIMER1_OVF_vect)
{
    fsm_random();
}

/**
 *  Brief: Call functions to generate psudo-random values.
 */
void fsm_random(void)
{
    static uint16_t values = 0;
    static uint8_t last = 0;
    static uint8_t new = 0;
    char uart_string[5];

    switch (current_state) {
    case IDLE_STATE:
        if (values < 20) {
            current_state = RAND4_STATE;
        } else if (values < 100) {
            if (values == 20) {
                last = 0;
                uart_puts("\r\n\r\n");
            }
            current_state = RAND8_STATE;
        }
        break;

    // Call 4-bit LFSR generator
    case RAND4_STATE:
        new = rand4_asm(last);
        values++;
        current_state = UART_STATE;
        break;

    // Call 8-bit LFSR generator
    case RAND8_STATE:
        new = rand8_asm(last);
        values++;
        current_state = UART_STATE;
        break;

    // Send pseudo-random value to UART
    case UART_STATE:
        itoa(new, uart_string, 10);
        uart_puts(" "); uart_puts(uart_string);
        last = new;
        current_state = IDLE_STATE;
        break;

    default:
        current_state = IDLE_STATE;
    }
}

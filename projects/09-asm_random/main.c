/*
 * ---------------------------------------------------------------------
 * Author:      Tomas Fryza
 *              Dept. of Radio Electronics, Brno Univ. of Technology
 * Created:     2017-11-09
 * Last update: 2019-11-14
 * Platform:    ATmega328P, 16 MHz, AVR 8-bit Toolchain 3.6.2
 * ---------------------------------------------------------------------
 * Description:
 *    Implementations of 8- and 16-bit LFSR-based (Linear Feedback Shift
 *    Register) pseudo-random generators in AVR assembly.
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
    RAND16_STATE
} state_t;

/* Define ------------------------------------------------------------*/
#define UART_BAUD_RATE 9600
#define N_GEN   30

/* Variables ---------------------------------------------------------*/
state_t current_state = IDLE_STATE;

/* Function prototypes -----------------------------------------------*/
void fsm_random(void);
/**
 *  Brief:  LFSR-based 8-bit pseudo-random generator.
 *  Input:  current_value - Current value of 8-bit shift register
 *  Return: Updated value of 8-bit shift register
 *  Note:   Function is implemented in AVR assembly.
 */
extern uint8_t rand8_asm(uint8_t current_value);

/* Functions ---------------------------------------------------------*/
/**
 *  Brief:  Main program. Generate a sequence of preudo-random values 
 *          using 8-bit and 16-bit functions.
 *  Input:  None
 *  Return: None
 */
int main(void)
{
    // UART: asynchronous, 8-bit data, no parity, 1-bit stop
    uart_init(UART_BAUD_SELECT(UART_BAUD_RATE, F_CPU));

    /* Timer1
     * TODO: Configure Timer1 clock source and enable overflow 
     *       interrupt every 33 msec. */
    TCCR1B |= _BV(CS11);
    TIMSK1 |= _BV(TOIE1);

    // Enables interrupts by setting the global interrupt mask
    sei();

    // Put strings to ringbuffer for transmitting via UART.
    uart_puts("\r\n---Pseudo random generator---");

    // Infinite loop
    for (;;) {
    }

    // Will never reach this
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
    static uint8_t values = 0;
    static uint8_t last = 0;
    static uint8_t new = 0;
    char uart_string[5];

    switch (current_state) {
    case IDLE_STATE:
        if (values < N_GEN) {
            current_state = RAND8_STATE;
        }
        break;

    // Call 8-bit LFSR generator
    case RAND8_STATE:
        new = rand8_asm(last);
        itoa(new, uart_string, 10);
        uart_puts(" "); uart_puts(uart_string);
        last = new;

        values++;
        if (values > N_GEN) {
            current_state = IDLE_STATE;
        }
        break;

    // Call 4-bit LFSR generator
    case RAND4_STATE:
        // TODO: Program 4-bit generator
        current_state = IDLE_STATE;
        break;

    // Call 16-bit LFSR generator
    case RAND16_STATE:
        // TODO: Program 16-bit generator
        current_state = IDLE_STATE;
        break;

    default:
        current_state = IDLE_STATE;
    }
}

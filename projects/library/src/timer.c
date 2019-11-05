/***********************************************************************
 * Title:    Timer library
 * Author:   Tomas Fryza, Brno University of Technology, Czechia
 * Software: avr-gcc, tested with avr-gcc 4.9.2
 * Hardware: Any AVR
 *
 * Copyright (c) 2019 Tomas Fryza
 * This work is licensed under the terms of the MIT license.
 *
 **********************************************************************/

/* Includes ----------------------------------------------------------*/
#include "timer.h"

/* Define ------------------------------------------------------------*/

/* Functions ---------------------------------------------------------*/
void TIM_config_prescaler(uint8_t timer_name,
                          uint8_t presc_val)
{
    /* Timer/Counter0 */
    if (timer_name == TIM0) {
        switch (presc_val) {
            case TIM_PRESC_1:
                /* 001 */
                TCCR0B = TCCR0B & ~_BV(CS02);
                TCCR0B = TCCR0B & ~_BV(CS01);
                TCCR0B = TCCR0B |  _BV(CS00);
                break;
            case TIM_PRESC_8:
                /* 010 */
                TCCR0B = TCCR0B & ~_BV(CS02);
                TCCR0B = TCCR0B |  _BV(CS01);
                TCCR0B = TCCR0B & ~_BV(CS00);
                break;
            case TIM_PRESC_64:
                /* 011 */
                TCCR0B = TCCR0B & ~_BV(CS02);
                TCCR0B = TCCR0B |  _BV(CS01);
                TCCR0B = TCCR0B |  _BV(CS00);
                break;
            case TIM_PRESC_256:
                /* 100 */
                TCCR0B = TCCR0B |  _BV(CS02);
                TCCR0B = TCCR0B & ~_BV(CS01);
                TCCR0B = TCCR0B & ~_BV(CS00);
                break;
            case TIM_PRESC_1024:
                /* 101 */
                TCCR0B = TCCR0B |  _BV(CS02);
                TCCR0B = TCCR0B & ~_BV(CS01);
                TCCR0B = TCCR0B |  _BV(CS00);
                break;
            case TIM_STOP:
            default:
                /* 000: No clock source (Timer/Counter stopped) */
                TCCR0B = TCCR0B & ~_BV(CS02);
                TCCR0B = TCCR0B & ~_BV(CS01);
                TCCR0B = TCCR0B & ~_BV(CS00);
        }
    }
    /* Timer/Counter1 */
    else if (timer_name == TIM1) {
        // TODO: Set prescaler values for Timer/Counter1
    }
    /* Timer/Counter2 */
    else {
        // TODO: Set prescaler values for Timer/Counter2
    }
}

/*--------------------------------------------------------------------*/
void TIM_config_interrupt(uint8_t timer_name,
                          uint8_t interr_mode)
{
    /* Timer/Counter0 */
    if (timer_name == TIM0) {
        switch (interr_mode) {
            case TIM_OVERFLOW_ENABLE:
                TIMSK0 = TIMSK0 | _BV(TOIE0);
                break;
            case TIM_OVERFLOW_DISABLE:
                TIMSK0 = TIMSK0 & ~_BV(TOIE0);
                break;
            default:
                /* Disable overflow interrupt */
                TIMSK0 = TIMSK0 & ~_BV(TOIE0);
        }
    }
    /* Timer/Counter1 */
    else if (timer_name == TIM1) {
        // TODO: Enable/disable interupt for Timer/Counter1
    }
    /* Timer/Counter2 */
    else {
        // TODO: Enable/disable interupt for Timer/Counter2
    }
}

/***********************************************************************
 * Title:    Timer library
 * Author:   Tomas Fryza, Brno University of Technology, Czechia
 * Software: avr-gcc, tested with avr-gcc 4.9.2
 * Hardware: Any AVR
 *
 * MIT License
 *
 * Copyright (c) 2019 Tomas Fryza
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
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
                TCCR0B = TCCR0B | _BV(CS00);
                break;
            case TIM_PRESC_8:
                /* 010 */
                TCCR0B = TCCR0B & ~_BV(CS02);
                TCCR0B = TCCR0B | _BV(CS01);
                TCCR0B = TCCR0B & ~_BV(CS00);
                break;
            case TIM_PRESC_64:
                /* 011 */
                TCCR0B = TCCR0B & ~_BV(CS02);
                TCCR0B = TCCR0B | _BV(CS01);
                TCCR0B = TCCR0B | _BV(CS00);
                break;
            case TIM_PRESC_256:
                /* 100 */
                TCCR0B = TCCR0B | _BV(CS02);
                TCCR0B = TCCR0B & ~_BV(CS01);
                TCCR0B = TCCR0B & ~_BV(CS00);
                break;
            case TIM_PRESC_1024:
                /* 101 */
                TCCR0B = TCCR0B | _BV(CS02);
                TCCR0B = TCCR0B & ~_BV(CS01);
                TCCR0B = TCCR0B | _BV(CS00);
                break;
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

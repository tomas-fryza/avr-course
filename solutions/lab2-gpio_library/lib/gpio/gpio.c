/***********************************************************************
 * 
 * GPIO library for AVR-GCC.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2019 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 *
 **********************************************************************/


/* Includes ----------------------------------------------------------*/
#include "gpio.h"


/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: GPIO_mode_output()
 * Purpose:  Configure one output pin.
 * Input(s): reg - Address of Data Direction Register, such as &DDRB
 *           pin - Pin designation in the interval 0 to 7
 * Returns:  none
 **********************************************************************/
void GPIO_mode_output(volatile uint8_t *reg, uint8_t pin)
{
    *reg = *reg | (1<<pin);
}


/**********************************************************************
 * Function: GPIO_mode_input_pullup()
 * Purpose:  Configure one input pin and enable pull-up.
 * Input(s): reg - Address of Data Direction Register, such as &DDRB
 *           pin - Pin designation in the interval 0 to 7
 * Returns:  none
 **********************************************************************/
void GPIO_mode_input_pullup(volatile uint8_t *reg, uint8_t pin)
{
    *reg = *reg & ~(1<<pin);  // Data Direction Register
    reg++;                    // Change pointer to Data Register
    *reg = *reg | (1<<pin);   // Data Register
}


/**********************************************************************
 * Function: GPIO_write_low()
 * Purpose:  Write one pin to low value.
 * Input(s): reg - Address of Port Register, such as &PORTB
 *           pin - Pin designation in the interval 0 to 7
 * Returns:  none
 **********************************************************************/
void GPIO_write_low(volatile uint8_t *reg, uint8_t pin)
{
    *reg = *reg & ~(1<<pin);
}


/**********************************************************************
 * Function: GPIO_write_high()
 * Purpose:  Write one pin to high value.
 * Input(s): reg - Address of Port Register, such as &PORTB
 *           pin - Pin designation in the interval 0 to 7
 * Returns:  none
 **********************************************************************/
void GPIO_write_high(volatile uint8_t *reg, uint8_t pin)
{
    *reg = *reg | (1<<pin);
}


/**********************************************************************
 * Function: GPIO_read()
 * Purpose:  Read a value from input pin.
 * Input(s): reg - Address of Pin Register, such as &PINB
 *           pin - Pin designation in the interval 0 to 7
 * Returns:  Pin value
 **********************************************************************/
uint8_t GPIO_read(volatile uint8_t *reg, uint8_t pin)
{
    uint8_t temp;

    temp = *reg & (1<<pin);

    if (temp != 0) {
        return 1;
    }
    else {
        return 0;
    }
}


/**********************************************************************
 * Function: GPIO_mode_input_nopull()
 **********************************************************************/


/**********************************************************************
 * Function: GPIO_write_toggle()
 **********************************************************************/

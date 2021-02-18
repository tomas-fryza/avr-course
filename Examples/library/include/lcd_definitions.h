#ifndef LCD_DEFINITIONS_H
#define LCD_DEFINITIONS_H

/***********************************************************************
 * 
 * Adjusting the display settings. All definitions added to the file 
 * "lcd_definitions.h" will override the default definitions from 
 * "lcd.h" (see Peter Fleury's LCD library for HD44780 based LCDs).
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2019-2021 Tomas Fryza, Peter Fleury
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 *
 **********************************************************************/

/**
 * @file 
 * @defgroup fryza_lcd LCD Definitions <lcd_definitions.h>
 * @code #include "lcd_definitions.h" @endcode
 *
 * @brief Adjusting the display settings.
 *
 * All definitions added to the file "lcd_definitions.h" will override 
 * the default definitions from "lcd.h" (see Peter Fleury's LCD library
 * for HD44780 based LCDs).
 *
 * @author Tomas Fryza, Peter Fleury, Dept. of Radio Electronics,
 *         Brno University of Technology, Czechia
 * @copyright (c) 2019-2021 Tomas Fryza, Peter Fleury, This work is 
 *                licensed under the terms of the MIT license
 * @{
 */

/* Defines -----------------------------------------------------------*/
/**
 * @name  Definitions for Display Size
 * Number of visible lines and characters per line of the display.
 *
 * @note All definitions added to the file lcd_definitions.h will 
 * override the default definitions from lcd.h. Add -D_LCD_DEFINITIONS_FILE
 * to the CDEFS section in the Makefile.
 */
#define LCD_LINES 2 /**< @brief Number of visible lines of the display */
#define LCD_DISP_LENGTH 16 /**< @brief Visibles characters per line of the display */

/**
 * @name Definitions for 4-bit IO mode
 * 4-bit mode definition of LCD signals on the Arduino Uno LCD Keypad Shield.
 *
 * The four LCD data lines and the two control lines RS, E can be on the
 * same port or on different ports. R/W pin is directly connected to GND
 * on LCD Keypad Shield and cannot be controlled.
 *
 * @note All definitions added to the file lcd_definitions.h will 
 * override the default definitions from lcd.h. Add -D_LCD_DEFINITIONS_FILE
 * to the CDEFS section in the Makefile.
 */
#define LCD_PORT        PORTD
#define LCD_DATA0_PORT  LCD_PORT
#define LCD_DATA1_PORT  LCD_PORT
#define LCD_DATA2_PORT  LCD_PORT
#define LCD_DATA3_PORT  LCD_PORT
#define LCD_DATA0_PIN   PD4 /**< @brief Pin for HD44780 data pin D4 */
#define LCD_DATA1_PIN   PD5 /**< @brief Pin for HD44780 data pin D5 */
#define LCD_DATA2_PIN   PD6 /**< @brief Pin for HD44780 data pin D6 */
#define LCD_DATA3_PIN   PD7 /**< @brief Pin for HD44780 data pin D7 */
#define LCD_RS_PORT     PORTB
#define LCD_RS_PIN      PB0
#define LCD_E_PORT      PORTB
#define LCD_E_PIN       PB1
// R/W pin is connected to GND on LCD Keypad Shield

/** @} */

#endif

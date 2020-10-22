#ifndef LCD_DEFINITIONS_H
#define LCD_DEFINITIONS_H

/***********************************************************************
 * 
 * Adjusting the display settings. All definitions added to the file 
 * "lcd_definitions.h" will override the default definitions from 
 * "lcd.h" (see Peter Fleury's LCD library for HD44780 based LCDs).
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2019-2020 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 *
 **********************************************************************/

/* Defines -----------------------------------------------------------*/
/**
 * @brief Number of visible lines and characters per line of the 
 *        display.
 */
#define LCD_LINES       2
#define LCD_DISP_LENGTH 16

/**
 * @brief 4-bit mode definition of LCD signals on the Arduino Uno LCD
 *        Keypad Shield.
 */
#define LCD_PORT        PORTD
#define LCD_DATA0_PORT  LCD_PORT
#define LCD_DATA1_PORT  LCD_PORT
#define LCD_DATA2_PORT  LCD_PORT
#define LCD_DATA3_PORT  LCD_PORT
#define LCD_DATA0_PIN   PD4     // HD44780 pin D4
#define LCD_DATA1_PIN   PD5     // HD44780 pin D5
#define LCD_DATA2_PIN   PD6     // HD44780 pin D6
#define LCD_DATA3_PIN   PD7     // HD44780 pin D7
#define LCD_RS_PORT     PORTB
#define LCD_RS_PIN      PB0
#define LCD_E_PORT      PORTB
#define LCD_E_PIN       PB1
// R/W pin is connected to GND on LCD Keypad Shield

#endif

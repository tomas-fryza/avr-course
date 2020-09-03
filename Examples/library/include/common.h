#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

/***********************************************************************
 * 
 * Common functions and defines.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2019 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 *
 **********************************************************************/

/**
 * @file  common.h
 * Common functions and defines.
 *
 * @copyright (c) 2019 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 */

/* Define ------------------------------------------------------------*/
/**
 * Define address of data direction register of port _x.
 */
#define DDR(_x) (*(&_x - 1))

/**
 * Define address of input register of port _x.
 */
#define PIN(_x) (*(&_x - 2))

#endif /* COMMON_H_INCLUDED */

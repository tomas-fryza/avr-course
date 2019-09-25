#ifndef LCD_DEFINITIONS_H
#define LCD_DEFINITIONS_H

/* Arduino Uno LCD Keypad Shield */
#define LCD_PORT      PORTD /* LCD data port */
#define LCD_DATA0_PIN PD4   /* 4-bit data pins */
#define LCD_DATA1_PIN PD5
#define LCD_DATA2_PIN PD6
#define LCD_DATA3_PIN PD7
#define LCD_RS_PORT   PORTB /* RS port */
#define LCD_RS_PIN    PB0   /* RS pin */
#define LCD_E_PORT    PORTB /* Enable port */
#define LCD_E_PIN     PB1   /* Enable pin */
/* R/W pin is connected to GND */

#endif // ifndef LCD_DEFINITIONS_H

### LCD display module

1. In your words, describe what ASCII table is.
   * ASCII table:

2. (Hand-drawn) picture of time signals between ATmega328P and LCD keypad shield (HD44780 driver) when transmitting three character data `De2`.

   ![your figure]()


### Custom characters

1. Code listing of two custom character definition. Always use syntax highlighting and meaningful comments:

```c
/* Variables ---------------------------------------------------------*/
// Custom character definition
uint8_t customChar[16] = {
    // WRITE YOUR CODE HERE

};
```


1. Listing of `TIMER2_OVF_vect` interrupt routine with complete stopwatch code, ie. displaying minutes, seconds, and tenths of seconds in the form of `minutes:seconds.tenths`. Always use syntax highlighting, meaningful comments, and follow C guidelines:

   ```c
   ISR(TIMER2_OVF_vect)
   {
       static uint8_t no_of_overflows = 0;
       static uint8_t tenths = 0;  // Tenths of a second
       static uint8_t secs = 0;    // Seconds
       char string[2];             // String for converted numbers by itoa()

       no_of_overflows++;
       if (no_of_overflows >= 6)
       {
           // Do this every 6 x 16 ms = 100 ms
           no_of_overflows = 0;

           // Count tenth of seconds 0, 1, ..., 9, 0, 1, ...


           itoa(tenths, string, 10);  // Convert decimal value to string
           lcd_gotoxy(7, 0);
           lcd_puts(string);
       }
       // Else do nothing and exit the ISR
   }
   ```

# Lab 4: INSERT_YOUR_FIRSTNAME INSERT_YOUR_LASTNAME

### Stopwatch

1. Listing of `TIMER2_OVF_vect` interrupt routine with complete stopwatch code, ie. displaying minutes, seconds, and tenths of seconds in the form of `minutes:seconds.tenths`. Always use syntax highlighting, meaningful comments, and follow C guidelines:

   ```c
   ISR(TIMER2_OVF_vect)
   {
       static uint8_t no_of_overflows = 0;
       static uint8_t tens = 0;  // Tenths of a second
       static uint8_t secs = 0;  // Seconds
       ...
       char string[2] = "  ";    // String for converted numbers by itoa()

       no_of_overflows++;
       if (no_of_overflows >= 6)
       {
           // Do this every 6 x 16 ms = 100 ms
           no_of_overflows = 0;
           ...

           itoa(tens, string, 10);  // Convert decimal value to string
           lcd_puts(string);
           ...
       }
       // Else do nothing and exit the ISR
   }
   ```

### Kitchen alarm

2. Schema of a kitchen alarm application that counts doen the time with an LCD, one LED and three push buttons: start, +1 minute, -1 minute. Use the +1/-1 minute buttons to increment/decrement the timer value. After pressing the Start button, the countdown starts. The countdown value is shown on the display in the form of mm.ss (minutes.seconds). At the end of the countdown, the LED will start blinking. The image can be drawn on a computer or by hand. Always name all components and their values.

   ![your figure]()

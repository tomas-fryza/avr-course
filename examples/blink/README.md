# Blink a LED

Source code is [here](main.c).

The preprocessor will process directives that are inserted into the C source code. These directives allow additional actions to be taken on the C source code before it is compiled into object code. Directives are not part of the C language itself. Preprocessor directives begin with a pound (`#`) symbol and may have several arguments. Do NOT put a semicolon character at the end of directives. This is a common mistake.

```c
#define LED_GREEN   PB5    // AVR pin where green LED is connected
#define SHORT_DELAY 250    // Delay in milliseconds
```

Preprocessor directive also allows for conditional compilation. The `#ifndef` means "if not defined". The `#ifndef` directive must be closed by `#endif`.
                        
```c
#ifndef F_CPU
# define F_CPU 16000000    // CPU frequency in Hz required for delay
#endif
```

Include another C language file into the current file at the location of the `#include` statement prior to compiling the source code.

```c
#include <util/delay.h>    // Functions for busy-wait delay loops
#include <avr/io.h>        // AVR device-specific IO definitions
```

Main function is where the program execution begins. Each function suppose to have a brief comment.

```c
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Toggle one LED and use delay library.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    // This is a function's body
}
```

Logical operations are commonly used to process individual bits.

Operation | Operator | Description
:--: | :--: | :--
OR  | `\|` | Set bit to one
AND NOT | `& ~` | Clear bit to zero
XOR | `^` | Toggle/invert bit value
shift | `<<` | Shift bits to left

```c
// Set pin as output in Data Direction Register
// DDRB = DDRB or 0010 0000
DDRB = DDRB | (1<<LED_GREEN);

// Set pin LOW in Data Register (LED off)
// PORTB = PORTB and 1101 1111
PORTB = PORTB & ~(1<<LED_GREEN);

// Invert LED in Data Register
// PORTB = PORTB xor 0010 0000
PORTB = PORTB ^ (1<<LED_GREEN);
```

All embedded applications have a for-ever loop within main function.

```c
// Infinite loop
while (1)
{
    // This is a loop's body
}
```

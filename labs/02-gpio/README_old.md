
2. Any function in C contains a declaration (function prototype), a definition (block of code, body of the function); each declared function can be executed (called). Study [this article](https://www.programiz.com/c-programming/c-user-defined-functions) and complete the missing sections in the following user defined function declaration, definition, and call.

```c
#include <avr/io.h>

// Function declaration (prototype)
uint16_t calculate(uint8_t, ***    );

int main(void)
{
    uint8_t a = 210;
    uint8_t b = 15;
    uint16_t c;

    // Function call
    c = ***      (a, b);

    // Infinite loop
    while (1) ;

    // Will never reach this
    return 0;
}

// Function definition (body)
***      calculate(uint8_t x, uint8_t y)
{
    uint16_t result;    // result = x^2 + 2xy + y^2

    result = x*x;
    ***
    ***
    return result;
}
```





Run Git Bash (Windows) of Terminal (Linux), navigate to your working directory, and update local repository.

```bash
## Windows Git Bash:
$ cd d:/Documents/
$ cd your-name/
$ ls
digital-electronics-2/
$ cd digital-electronics-2/
$ git pull

## Linux:
$ cd
$ cd Documents/
$ cd your-name/
$ ls
digital-electronics-2/
$ cd digital-electronics-2/
$ git pull
```

Create a new working folder `labs/03-gpio` for this exercise.

```bash
## Windows Git Bash or Linux:
$ cd labs/
$ mkdir 03-gpio
```




### Version: Atmel Studio 7

1. Create a new GCC C Executable Project for ATmega328P within `03-gpio` working folder and copy/paste [template code](main.c) to your `main.c` source file.

2. In **Solution Explorer** click on the project name, then in menu **Project**, select **Add New Item... Ctrl+Shift+A** and add a new C/C++ Include File `gpio.h`. Copy/paste the [template code](../library/include/gpio.h) into it.

### Version: Command-line toolchain

1. If you haven't already done so, copy folder `library` from `Examples` to `Labs`. Check if `Makefile.in` settings file exists in `Labs` folder.

```bash
## Linux:
$ cp -r ../examples/library .
$ ls
01-tools  02-leds  03-gpio  Makefile.in  library
```

2. Copy `main.c` and `Makefile` files from previous lab to `labs/03-gpio` folder.

3. Copy/paste [template code](main.c) to your `03-gpio/main.c` source file.

4. Create a new library header file in `labs/library/include/gpio.h` and copy/paste the [template code](../library/include/gpio.h) into it.



### Version: Atmel Studio 7

1. In **Solution Explorer** click on the project name, then in menu **Project**, select **Add New Item... Ctrl+Shift+A** and add a new C File `gpio.c`. Copy/paste the [template code](../library/gpio.c) into it.

### Version: Command-line toolchain

1. Create a new `labs/library/gpio.c` library source file and copy/paste the [template code](../library/gpio.c) into it.

2. Add the source file of gpio library between the compiled files in `03-gpio/Makefile`.

```Makefile
# Add or comment libraries you are using in the project
#SRCS += $(LIBRARY_DIR)/lcd.c
#SRCS += $(LIBRARY_DIR)/uart.c
#SRCS += $(LIBRARY_DIR)/twi.c
SRCS += $(LIBRARY_DIR)/gpio.c
```



<a name="part4"></a>

## Part 4: Final application

1. In `03-gpio/main.c` rewrite the LED switching application from the previous exercise using the library functions; make sure that only one LED is turn on at a time, while the other is off. Do not forget to include gpio header file to your main application `#include "gpio.h"`. When calling a function with a pointer, use the address-of-operator `&variable` according to the following example:

```c
#include <gpio.h>

    /* GREEN LED */
    GPIO_config_output(&DDRB, LED_GREEN);
```

2. Compile it and download to Arduino Uno board or load `*.hex` firmware to SimulIDE circuit. Observe the correct function of the application using the flashing LEDs and the push button.




Extra. Use basic [Goxygen commands](http://www.doxygen.nl/manual/docblocks.html#specialblock) inside the C-code comments and prepare your `gpio.h` library for later easy generation of PDF documentation. Get inspired by the `GPIO_config_output` function in the `gpio.h` file.

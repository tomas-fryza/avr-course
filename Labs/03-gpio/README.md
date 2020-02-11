# Lab 3: Creation of user library for GPIO control

#### Contents

1. [Lab prerequisites](#Lab-prerequisites)
2. [Used hardware components](#Used-hardware-components)
3. [Synchronize Git and create a new project](#Synchronize-Git-and-create-a-new-project)
4. [Header file](#Header-file)
5. [Source file](#Source-file)
6. [Final application](#Final-application)
7. [Clean project and synchronize git](#Clean-project-and-synchronize-git)
8. [Ideas for other tasks](#Ideas-for-other-tasks)


## Lab prerequisites

1. What is the meaning of `volatile` keyword in C? What is the difference between operators `*` and `&`, such as `*reg` and `&DDRB`?

2. Complete the following table with C data types.

    | **Data type** | **Number of bits** | **Range** |
    | :-: | :-: | :-: |
    | `uint8_t` | 8 | 0, 1, ..., 255 |
    | `int8_t` |  |  |
    | `uint16_t` |  |  |
    | `int16_t` |  |  |
    | `float` |  | -3.4e+38, ..., 3.4e+38 |
    | `void` |  |  |

3. Use the [ATmega328P datasheet](https://www.microchip.com/wwwproducts/en/ATmega328p) and complete the following table with I/O ports. Let PUD (Pull-up Disable) bit in MCUCR (MCU Control Register) is 0 by default.

    | **DDRB5** | **PORTB5** | **I/O** | **Pull-up** | **Description** |
    | :-: | :-: | :-: | :-: | :-- |
    | 0 | 0 | Input | No | Three-state, high impedance |
    | 0 | 1 |  |  |  |
    | 1 | 0 |  |  |  |
    | 1 | 1 |  |  |  |


## Used hardware components

1. [ATmega328P](https://www.microchip.com/wwwproducts/en/ATmega328P) 8-bit AVR microcontroller.
2. [Arduino Uno](../../Docs/arduino_shield.pdf) board.
3. [300-pin breadboard](https://www.gme.cz/nepajive-kontaktni-pole-zy-60).
4. [Male-male wires](https://arduino-shop.cz/arduino/1063-arduino-vodice-samec-samec-40-kusu-1500635966.html) for interconnections.


## Synchronize Git and create a new project

1. In Visual Studio Code editor (VS Code) open your Digital-electronics-2 working directory and [synchronize the contents](https://github.com/joshnh/Git-Commands) with GitHub.

    ```bash
    $ pwd
    /home/lab661/Documents/your-name/Digital-electronics-2
    $ git pull
    ```

2. Create a new folder `Labs/03-gpio` and copy three files from the last project.

    ```bash
    $ cd Labs/
    $ mkdir 03-gpio
    $ cp 02-leds/main.c 02-leds/Makefile 02-leds/README.md 03-gpio/
    $ cd 03-gpio/
    $ ls
    main.c  Makefile  README.md
    ```


## Header file

*[A function prototype](https://www.programiz.com/c-programming/c-user-defined-functions) is simply the declaration of a function that specifies function's name, parameters and return type. It doesn't contain function body. A function prototype gives information to the compiler that the function may later be used in the program.*

1. Create a new library header file `library/Include/gpio.h` and define function prototypes according to the following table.

    | **Return** | **Function name** | **Function parameters** |
    | :-: | :-- | :-- |
    | `void` | `GPIO_output` | `volatile uint8_t *reg, uint8_t pin` |
    | `void` | `GPIO_write` | `volatile uint8_t *reg, uint8_t pin, uint8_t val` |
    | `void` | `GPIO_toggle` | `volatile uint8_t *reg, uint8_t pin` |
    | `void` | `GPIO_input_nopull` | `volatile uint8_t *reg, uint8_t pin` |
    | `void` | `GPIO_input_pullup` | `volatile uint8_t *reg, uint8_t pin` |
    | `uint8_t` | `GPIO_read` | `volatile uint8_t *reg, uint8_t pin` |

2. Why is it necessary to use guard directives `#ifndef`, `#define`, `#endif` in header file?

    ```C
    #ifndef GPIO_H_INCLUDED
    #define GPIO_H_INCLUDED

    #include <avr/io.h>

    void GPIO_output(volatile uint8_t *reg, uint8_t pin);
    ...
    
    #endif /* GPIO_H_INCLUDED */
    ```

    > See [gpio header template](../library/Include/gpio.h) for complete list of declared functions.
    >


## Source file

1. Create a source file `library/Source/gpio.c` and define all declared functions. See AVR Libc Reference Manual how to pass an [IO port as a parameter](https://www.microchip.com/webdoc/AVRLibcReferenceManual/FAQ_1faq_port_pass.html) to a function.

    ```C
    #include "gpio.h"

    /* Configures one output pin */
    void GPIO_output(volatile uint8_t *reg, uint8_t pin) {

        *reg = *reg | _BV(pin);
    }
    ...
    ```

2. Add the source file of gpio library between the compiled files in `03-gpio/Makefile`.

    ```Makefile
    # Add or comment libraries you are using in the project
    #SRCS += $(LIBRARY_DIR)/Source/lcd.c
    #SRCS += $(LIBRARY_DIR)/Source/uart.c
    #SRCS += $(LIBRARY_DIR)/Source/twi.c
    SRCS += $(LIBRARY_DIR)/Source/gpio.c
    ```


## Final application

1. Rewrite the LED switching application from the previous exercise using the library functions. Do not forget to include gpio header file to your main application `#include "gpio.h"`.


## Clean project and synchronize git

1. Remove all binaries and object files from the working directory by command

    ```bash
    $ make clean
    ```

2. Use `cd ..` command in VS Code terminal and change the working directory to `Digital-electronics-2`. Then use [git commands](https://github.com/joshnh/Git-Commands) to add, commit, and push all local changes to your remote repository. Check the repository at GitHub web page for changes.

    ```bash
    $ pwd
    /home/lab661/Documents/your-name/Digital-electronics-2/Labs/03-gpio

    $ cd ..
    $ cd ..
    $ pwd
    /home/lab661/Documents/your-name/Digital-electronics-2

    $ git status
    $ git add <your-modified-files>
    $ git status
    $ git commit -m "[LAB] Creating 03-gpio lab"
    $ git status
    $ git push
    $ git status
    ```


## Ideas for other tasks

1. Use basic [Goxygen commands](http://www.doxygen.nl/manual/docblocks.html#specialblock) inside C-code comments and prepare your `gpio.h` library for easy PDF manual generation.

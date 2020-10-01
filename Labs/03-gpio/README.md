# Lab 3: User library for GPIO control

### Learning objectives

The purpose of this laboratory exercise is to learn how to create your own user libraries in C. Specifically, it will be a library for controlling GPIO pins.


## Preparation tasks (done before the lab at home)

Fill in the following table and specify the number of bits and numeric range for the specified data types, defined by C.

| **Data type** | **Number of bits** | **Range** | **Description** |
| :-: | :-: | :-: | :-- | 
| `uint8_t`  | 8 | 0, 1, ..., 255 | Unsigned 8-bit integer |
| `int8_t`   |  |  |  |
| `uint16_t` |  |  |  |
| `int16_t`  |  |  |  |
| `float`    |  | -3.4e+38, ..., 3.4e+38 | Single-precision floating-point |
| `void`     |  |  |  |





TBD:
Example of function declaration (prototype) and definition (body).




## Part 1: Synchronize repositories and create a new folder

Run Git Bash (Windows) of Terminal (Linux) and synchronize local and remote repositories.

```bash
## Windows Git Bash:
$ cd d:/Documents/
$ cd your-name/
$ cd Digital-electronics-2/
$ git pull

## Linux:
$ cd
$ cd Documents/
$ cd your-name/
$ cd Digital-electronics-2/
$ git pull
```

Create a new working folder `Labs/03-gpio` for this exercise.

```bash
## Windows Git Bash or Linux:
$ cd Labs/
$ mkdir 03-gpio
```












## Part 2: Header file

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

What is the meaning of `volatile` keyword in C? What is the difference between operators `*` and `&`, such as `*reg` and `&DDRB`

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


## Part 3: Source file

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


## Part 4: Final application

1. Rewrite the LED switching application from the previous exercise using the library functions. Do not forget to include gpio header file to your main application `#include "gpio.h"`.










## Synchronize repositories

Use [git commands](https://github.com/tomas-fryza/Digital-electronics-2/wiki/Git-useful-commands) to add, commit, and push all local changes to your remote repository. Check the repository at GitHub web page for changes.


## Experiments on your own

TBD:
1. Use basic [Goxygen commands](http://www.doxygen.nl/manual/docblocks.html#specialblock) inside C-code comments and prepare your `gpio.h` library for easy PDF manual generation.


## Lab assignment

1. GPIO example. Submit:
    * Xxx,
    * Screenshot of SimulIDE circuit.

2. Xxxx. Submit:
    * C code.

The deadline for submitting the task is the day before the next laboratory exercise. Use [BUT e-learning](https://moodle.vutbr.cz/) web page and submit a single PDF file.

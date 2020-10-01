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

Any function in C contains a declaration (function prototype), a definition (block of code, body of the function) and we can call such function.

Study [this article](https://www.programiz.com/c-programming/c-user-defined-functions) and complete the missing sections in the following user defined function declaration, definition, and call.

```C
#include <avr/io.h>

uint16_t calculate(uint8_t, ...    );   // Function prototype

int main(void)
{
    uint8_t a = 156;
    uint8_t b = 14;
    uint16_t c;

    c = ...      (a, b);    // Function call

    return 0;
}

...      calculate(uint8_t x, uint8_t y)    // Function definition
{
    uint16_t result;    // result = x^2 + 2xy + y^2

    result = x*x;
    ...
    ...
    return result;
}
```


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


## Part 2: Introduction and header file

For clarity and efficiency of the code, the individual parts of the application in C are divided into two types of files: header files and source files.

**Header file** is a file with extension `.h` and generally contains definitions of data types, function prototypes and C preprocessor commands. **Source file** is a file with extension `.c` and is used for implementations and source code. It is bad practice to mix usage of the two although it is possible.

C programs are highly dependent on functions. Functions are the basic building blocks of C programs and every C program is combination of one or more functions. There are two types of functions in C: **built-in functions** which are the part of C compiler and **user defined functions** which are written by programmers according to their requirement.

To use user defined function, three steps are involved:

* Function prototype or Function declaration (`*.h` file)
* Function definition (`*.c` file)
* Function call (`*.c` file)

*[A function prototype](https://www.programiz.com/c-programming/c-user-defined-functions) is simply the declaration of a function that specifies function's name, parameters and return type. It doesn't contain function body. A function prototype gives information to the compiler that the function may later be used in the program.*

***Function definition** contains the block of code to perform a specific task.*

*By **calling the function**, the control of the program is transferred to the function.*

A header file can be shared between several source files by including it with the C preprocessing directive `#include`.

If a header file happens to be included twice, the compiler will process its contents twice and it will result in an error. The standard way to prevent this is to enclose the entire real contents of the file in a conditional, like this:

```C
#ifndef HEADER_FILE_NAME
#define HEADER_FILE_NAME

// The body of entire header file

#endif
```

This construct is commonly known as a wrapper `#ifndef`. When the header is included again, the conditional will be false, because `HEADER_FILE_NAME` is already defined. The preprocessor will skip over the entire contents of the file, and the compiler will not see it twice.


### Version: Atmel Studio 7

Create a new project for ATmega328P within `03-gpio` working folder and copy/paste [template code](main.c) to your `main.c` source file.

Create a new `gpio.h` library header file and copy/paste the [template code](xxxx) into it.


### Version: Command-line toolchain

If you haven't already done so, copy folder `library` from `Examples` to `Labs`. Check if `firmware.in` settings file exists in `Labs` folder.

```bash
## Linux:
$ cp -r ../Examples/library .
$ ls
01-tools  02-leds  03-gpio  firmware.in  library
```

Copy `main.c` and `Makefile` files from previous lab to `Labs/03-gpio` folder.

Copy/paste [template code](main.c) to your `03-gpio/main.c` source file.

Create a new `Labs/library/include/gpio.h` library header file and copy/paste the [template code](xxxx) into it.


### Both versions

Complete the function prototypes definition in `gpio.h` file according to the following table.

| **Return** | **Function name** | **Function parameters** | **Description** |
| :-: | :-- | :-- | :-- |
| `void` | `GPIO_set_output` | `volatile uint8_t *reg, uint8_t pin` | Configure an output pin in Data Direction Register |
| `void` | `GPIO_set_input_nopull` | `volatile uint8_t *reg, uint8_t pin` | Configure an input pin in DDR without pull-up resistor |
| `void` | `GPIO_set_input_pullup` | `volatile uint8_t *reg, uint8_t pin` | Configure an input pin in DDR and enable pull-up resistor |
| `void` | `GPIO_write_low` | `volatile uint8_t *reg, uint8_t pin` | Set output pin in PORT register to low |
| `void` | `GPIO_write_high` | `volatile uint8_t *reg, uint8_t pin` | Set output pin in PORT register to high |
| `void` | `GPIO_toggle` | `volatile uint8_t *reg, uint8_t pin` | Toggle output pin value in PORT register |
| `uint8_t` | `GPIO_read` | `volatile uint8_t *reg, uint8_t pin` | Get input pin value from PIN register |

What is the meaning of `volatile` keyword in C? What is the difference between operators `*` and `&`, such as `*reg` and `&DDRB`


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

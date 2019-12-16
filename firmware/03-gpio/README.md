# Lab 3. Creation of own user library for GPIO control

#### Table of contents

1. [Lab prerequisites](#Lab-prerequisites)
2. [Synchronize Git and create a new project](#Synchronize-Git-and-create-a-new-project)
3. [Header file](#Header-file)
4. [Source file](#Source-file)
5. [Final application](#Final-application)
6. [Clean project and synchronize git](#Clean-project-and-synchronize-git)
7. [Ideas for other tasks](#Ideas-for-other-tasks)


## Lab prerequisites

TBD


## Synchronize Git and create a new project

1. In Visual Studio Code editor (VS Code) open your Digital-electronics-2 working directory and synchronize the contents with [GitHub](https://github.com/joshnh/Git-Commands).

    ```bash
    $ pwd
    /home/lab661/Documents/your-name/Digital-electronics-2
    $ git pull
    ```

2. Create a new folder `firmware/03-gpio` and copy three files from the last project.

    ```bash
    $ cd firmware/
    $ mkdir 03-gpio
    $ cp 02-leds/main.c 02-leds/Makefile 02-leds/README.md 03-gpio/
    $ cd 03-gpio/
    $ ls
    main.c  Makefile  README.md
    ```


## Header file

*[A function prototype](https://www.programiz.com/c-programming/c-user-defined-functions) is simply the declaration of a function that specifies function's name, parameters and return type. It doesn't contain function body. A function prototype gives information to the compiler that the function may later be used in the program.*

1. Create a new library header file `library/include/gpio.h` and define function prototypes according to the following table.

    | **Return** | **Function name** | **Function parameters** |
    |---|---|---|
    | `void` | `GPIO_output` | `volatile uint8_t *reg, uint8_t pin` |
    | `void` | `GPIO_write` | `volatile uint8_t *reg, uint8_t pin, uint8_t val` |
    | `void` | `GPIO_toggle` | `volatile uint8_t *reg, uint8_t pin` |
    | `void` | `GPIO_input_nopull` | `volatile uint8_t *reg, uint8_t pin` |
    | `void` | `GPIO_input_pullup` | `volatile uint8_t *reg, uint8_t pin` |
    | `uint8_t` | `GPIO_read` | `volatile uint8_t *reg, uint8_t pin` |

2. What is the meaning of `void` and `uint8_t` datatypes? What is the meaning of `volatile` keyword? What is the meaning of `*` symbol?

3. Why is it necessary to use guard directives `#ifndef`, `#define`, `#endif` in header file?

    ```C
    #ifndef GPIO_H_INCLUDED
    #define GPIO_H_INCLUDED

    #include <avr/io.h>

    void GPIO_output(volatile uint8_t *reg, uint8_t pin);
    ...
    
    #endif /* GPIO_H_INCLUDED */
    ```

    > See [gpio header template](../library/include/gpio.h) for complete list of declared functions.
    >


## Source file

1. Create a source file `library/source/gpio.c` and define all declared functions. See AVR Libc Reference Manual how to pass an [IO port as a parameter](https://www.microchip.com/webdoc/AVRLibcReferenceManual/FAQ_1faq_port_pass.html) to a function.

    ```C
    #include "gpio.h"

    /* Functions ---------------------------------------------------------*/
    void GPIO_output(volatile uint8_t *reg, uint8_t pin) {

        *reg = *reg | _BV(pin);
    }
    ...
    ```

2. Add the source file of gpio library between the compiled files in `03-gpio/Makefile`;

    ```Makefile
    # Add or comment libraries you are using in the project
    #SRCS += $(LIBRARY_DIR)/source/lcd.c
    #SRCS += $(LIBRARY_DIR)/source/uart.c
    #SRCS += $(LIBRARY_DIR)/source/twi.c
    SRCS += $(LIBRARY_DIR)/source/gpio.c
    ```


## Final application

1. Rewrite the LED switching application from the previous exercise using the library functions.


## Clean project and synchronize git

1. Remove all binaries and object files from the working directory by command

    ```bash
    $ make clean
    ```

2. Use `cd ..` command in VS Code terminal and change the working directory to `Digital-electronics-2`. Then use [git commands](https://github.com/joshnh/Git-Commands) to add, commit, and push all local changes to your remote repository. Check the repository at GitHub web page for changes.

    ```bash
    $ pwd
    /home/lab661/Documents/your-name/Digital-electronics-2/firmware/03-gpio

    $ cd ..
    $ cd ..
    $ pwd
    /home/lab661/Documents/your-name/Digital-electronics-2

    $ git status
    $ git add <your-modified-files>
    $ git commit -m "[PROJECT] Creating 03-gpio project"
    $ git push
    ```


## Ideas for other tasks

1. Use basic [Goxygen commands](http://www.doxygen.nl/manual/docblocks.html#specialblock) inside C-code comments and prepare your `gpio.h` library for easy PDF manual generation.

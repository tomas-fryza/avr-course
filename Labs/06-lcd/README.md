# Lab 6: Display devices, LCD display

### Learning objectives

The purpose of the laboratory exercise is to understand the serial control of Hitachi HD44780-based LCD character display. Another goal is to learn how to read documentation for library functions and use them in your own project.

![LCD-keypad shield](Images/arduino_uno_lcd.jpg)


## Preparation tasks (done before the lab at home)

Use schematic of the [LCD keypad shield](../../Docs/arduino_shield.pdf) and find out the connection of LCD display. What data and control signals are used? What is the meaning of these signals?

&nbsp;

&nbsp;

&nbsp;

&nbsp;

&nbsp;

&nbsp;

   | **LCD signal(s)** | **AVR pin(s)** | **Description** |
   | :-: | :-: | :-- |
   | RS | PB0 | Register selection signal. Selection between *Instruction register* (0) and *Data register* (1) |
   | R/W |  |  |
   | E |  |  |
   | D[3:0] |  |  |
   | D[7:4] |  |  |

What is the ASCII table? What are the values for uppercase letters `A` to `Z`, lowercase letters `a` to `z`, and numbers `0` to `9` in this table?

&nbsp;

&nbsp;

&nbsp;


## Part 1: Synchronize repositories and create a new folder

Run Git Bash (Windows) of Terminal (Linux), navigate to your working directory, and update local repository. Create a new working folder `Labs/06-lcd` for this exercise.


## Part 2: LCD display module

**LCD** (Liquid Crystal Display) is an electronic display device and can display any ASCII text. There are many different screen sizes e.g. 16x1, 16x2, 16x4, 20x4, 40x4 characters and each character is made of 5x8 pixel dots. LCD displays have different LED backlight in yellow-green, white and blue color. LCD modules are mostly available in COB (Chip-On-Board) type. With this method, the controller IC chip or driver (here: HD44780) is directly mounted on the backside of the LCD module itself.

The Hitachi HD44780 is an LCD driving chipset, and hence the driving software remains the same even for different screen sizes. The driver contains the character set but in addition you can also generate your own characters.

The HD44780 is capable of operating in 8-bit mode i.e. faster, but that means 11 microcontroller pins are needed. Because the speed is not really that important as the amount of data needed to drive the display is low, the 4-bit mode is more appropriate for microcontrollers since only 6 (or 7) pins are needed. Inside the HD44780 there is still an 8-bit operation so for 4-bit mode, two writes to get 8-bit quantity inside the chip are made (first high four bits and then low four bits with an E clock pulse).

In the lab, we are using a 16x2 LCD (it can display 16 characters per line and there are 2 such lines) with only 6 wires for the HD44780:
   * RS - register select. Selects the data or instruction register inside the HD44780,
   * E - enable. This loads the data into the HD44780 on the falling edge,
   * D7:4 - Upper nibble used in 4-bit mode.

Let the following image shows the communication between ATmega328P and LCD display in 4-bit mode. How does HD44780 driving chipset understand the sequence of these signals?

   &nbsp;
   ![Timing of LCD display](Images/lcd_capture_C.png)

The following signals are read on the first falling edge of the enable: `RS = 1` (data register) and high four bits are `D7:4 = 0100`. On the second falling edge of enable, the low four data bits are `D7:4 = 0011`. The whole byte transmitted to the LCD is therefore `0100_0011` (0x43) and according to the ASCII (American Standard Code for Information Interchange) table, it represents lettre `C`.



**TODO:**

https://microcontrollerslab.com/hitachi-hd44780-lcd-module/

The Hitachi HD44780 has many commands, here are the most useful: initialisation, xy location setting and print.

https://mil.ufl.edu/3744/docs/lcdmanual/commands.html
https://www.best-microcontroller-projects.com/hitachi-hd44780.html
https://components101.com/sites/default/files/component_datasheet/16x2%20LCD%20Datasheet.pdf







If you are an advanced programmer and would like to create your own library for interfacing your Microcontroller with this LCD module then you have to understand the HD44780 IC is working and commands which can be found its datasheet.



*In the lab, we are using [LCD library for HD44780 based LCDs](http://www.peterfleury.epizy.com/avr-software.html) developed by Peter Fleury*

1. Use online manual of LCD library and add the input parameters and description of the functions to the following table.

    | **Function** | **Parameter(s)** | **Description** |
    | :-: | :-: | :-- |
    | `lcd_init` | `LCD_DISP_OFF`<br>&nbsp;<br>&nbsp;<br>&nbsp; | Display off&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<br>&nbsp;<br>&nbsp;<br>&nbsp;
    | `lcd_clrscr` | | |
    | `lcd_home` | | |
    | `lcd_gotoxy` | | |
    | `lcd_putc` | | |
    | `lcd_puts` | | |

2. Use template from [teacher's GitHub]((https://github.com/tomas-fryza/Digital-electronics-2/blob/master/Labs/06-lcd/main.c)) and test all functions mentioned above. Comment (or uncomment) source files you need within the list of compiled files in `06-lcd/Makefile`.


## Decimal counter

1. According to the listing bellow, verify how you can convert a variable value to string and then display it on LCD. Display one variable value in decimal, binary, and hexadecimal. What are the parameters of standard C function `itoa`?

    ```C
    #include <stdlib.h>

    uint8_t value = 31;
    char lcd_string[3];
    ...

    itoa(value, lcd_string, 16);
    lcd_putc('$');
    lcd_puts(lcd_string);
    ```

2. Configure Timer1 clock source, enable its overflow interrupt, create a decimal counter from 0 to 255, and show the value on LCD display.


## User-defined symbols



The LCD character map is a table of information (memory locations) located on the controller. The map assigns a number between 0 and 255 to each letter, number and punctuation mark. When you want your customer to see a capital A, you send it number 64 and if you want it to display an 8 you send it a 122.



*User-defined symbols are represented by eight bytes (lines) and they are stored in the beginning of [CGRAM display memory](https://www.mikroe.com/ebooks/pic-microcontrollers-programming-in-c/additional-components).*

![lcd_symbols](../../Images/lcd_new_symbols.png "LCD new symbols")

1. Design at least two user characters, store them in the display memory according to the following code and display them on LCD.

    ```C
    /* Variables ---------------------------------------------------------*/
    // User-defined LCD chars
    uint8_t lcd_charset[] = {0x0a, ...};
    ...

    // Set pointer to beginning of CGRAM memory
    lcd_command(_BV(LCD_CGRAM));
    // Store new chars to memory line by line
    lcd_data(lcd_charset[0]);
    ...

    // Clear display for the first use
    lcd_clrscr();
    ...

    // Display first user-defined character
    lcd_putc(0x00);
    ```


## Clean project and synchronize git

Remove all binaries and object files from the working directory. Then use git commands, commit all modified/created files to your local repository and push them to remote repository or use VS Code options to perform these operations.


## Ideas for other tasks

1. Use new characters and create a bar graph at LCD. Let the bar state corresponds to decimal counter value, similar to the following figure.

![lcd_bargraph](../../Images/lcd_bar-graph_arduino.png "LCD bar graph")



https://protostack.com.au/2010/03/character-lcd-displays-part-1/
https://www.st.com/en/embedded-software/stsw-stm8063.html#documentation

Using these it is possible to create a simple bar graph to display a graphical representation of voltage etc.

[![university](https://img.shields.io/badge/university-Brno%20University%20of%20Technology-red.svg)](https://www.vutbr.cz/en/)
[![department](https://img.shields.io/badge/department-Dept.%20of%20Radio%20Electronics-blue)](https://www.facebook.com/URELBrno)
[![GitHub](https://img.shields.io/github/license/tomas-fryza/Digital-electronics-2)](https://choosealicense.com/licenses/mit/)
[![activity](https://img.shields.io/github/last-commit/tomas-fryza/Digital-electronics-2)](https://github.com/tomas-fryza/Digital-electronics-2/commits/master)

# Digital electronics 2

#### Table of contents

1. [Introduction](#Introduction)
2. [Hardware components](#Hardware-components)
3. [Software components](#Software-components)
4. [How to use AVR template on Linux](Docs/HOWTO_linux.md)
5. [How to use AVR template on Windows](Docs/HOWTO_windows.md)
6. [References](#References)
7. [License](#License)


## Introduction

The repository contains AVR examples for bachelor course [*Digital Electronics 2*](https://www.vutbr.cz/en/students/courses/detail/210896) at Brno University of Technology, Czechia. In folder `Docs` all manuals are stored. Folder `Docs/Hw` contains KiCad schematic of Arduino shields used in the course. All lab exercises are located within `Labs` folder and all screenshots and images are located in `Images` folder. Source and header files of LCD, TWI, and UART libraries are located in the `Labs/library` folder.

| **Lab exercise** | **Description** |
| :-- | :-- |
| [01-demo](Labs/01-demo) | Lab 1: Git version-control system, AVR toolchain |
| [02-leds](Labs/02-leds) | Lab 2: Control of GPIO, LED, push button |
| [03-gpio](Labs/03-gpio) | Lab 3: Creation of user library for GPIO control |
| [04-interrupts](Labs/04-interrupts) | Lab 4: Interrupts, Timers |
| [05-segment](Labs/05-segment) | Lab 5: Display devices, 7-segment display |
| [06-lcd](Labs/06-lcd) | Lab 6: Display devices, LCD display |
| [07-uart](Labs/07-uart) | Lab 7: ADC, serial communication, UART |
| [08-twi_scan](Labs/08-twi_scan) | Lab 8: Serial communication, I2C/TWI |
| [09-asm_random](Labs/09-asm_random) | Lab 9: Combining C and assembly source files |
| [project](Labs/project) | Lab 10--13: Project |


## Hardware components

The following hardware components are mainly used in the lab.

| **Component** | **Description** | **Manual** |
| :-: | :-- | :-: |
| [ATmega328P](https://www.microchip.com/wwwproducts/en/ATmega328P) | 8-bit microcontroller | [Instruction set](https://www.microchip.com/webdoc/avrassembler/avrassembler.wb_instruction_list.html) |
| [Arduino Uno board](https://arduino-shop.cz/arduino/1353-klon-arduino-uno-r3-atmega328p-ch340-mini-usb-1466635561.html) | Low-cost clone of Arduino UNO R3 CH340 mini USB | [Schematic](Docs/arduino_shield.pdf) |
| [Logic analyzer](https://www.ebay.com/sch/i.html?LH_CAds=&_ex_kw=&_fpos=&_fspt=1&_mPrRngCbx=1&_nkw=24mhz%20logic%20analyzer&_sacat=&_sadis=&_sop=12&_udhi=&_udlo=) | 24MHz 8-channel logic analyzer | [Software](https://www.saleae.com/) |
| [Multi-function shield](https://www.gme.cz/experiment-shield-pro-arduino) | Multi-function shield with four LEDs, three push buttons, four seven-segment displays, and others | [Schematic](Docs/arduino_shield.pdf) |
| [LCD keypad hield](https://arduino-shop.cz/en/arduino-platform/899-arduino-lcd-shield-1420670167.html) | LCD and keypad shield with LCD and five push buttons | [Schematic](Docs/arduino_shield.pdf) |
| [DHT12](https://arduino-shop.cz/arduino/1977-i2c-teplomer-a-vlhkomer-dht12-digitalni.html) | I2C humidity and temperature sensor | [Data sheet](Docs/dht12_manual.pdf) |
| [DS3231](https://arduino-shop.cz/hledani.php?q=DS3231&n_q=) | I2C real time clock | [Data sheet](Docs/ds3231_manual.pdf) |
| [Ultrasonic HC-SR04](https://components101.com/ultrasonic-sensor-working-pinout-datasheet) | HC-SR04 ultrasonic sensor |
| [ESP8266](https://arduino-shop.cz/arduino/911-internet-veci-je-tady-tcp-ip-wifi-esp8266-1420990568.html) | Wi-Fi module | [AT commands](Docs/esp8266_at_instruction_set.pdf) |
| [Joystick PS2](https://arduino-shop.cz/arduino/884-arduino-joystick-ps2.html) | Analog Joystick PS2 |

![uno](Images/arduino_uno_water.jpg "Ultrasonic sensor, temperature/humidity sensor, WiFi module")


## Software components

| **Component** | **Description** | **Manual** |
| :-: | :-- | :-: |
| [VS Code](https://code.visualstudio.com/) | Visual Studio Code |
| [Saleae](https://www.saleae.com/downloads/) | Saleae logic analyser |
| [Linux Mint](https://linuxmint.com/download_all.php) | Linux Mint 18.2 "Sonya" - Xfce (64-bit) |

![vscode](Images/screenshot_vscode.png "Visual Studio Code")


## References

1. [Git, free and open source distributed version control system](https://git-scm.com/)
2. [GNU Make tool for Linux](https://www.gnu.org/software/make/)
3. [Minimalist GNU for Windows](http://www.mingw.org/wiki/Getting_Started/)
4. [AVRDUDE, software for programming Atmel AVR Microcontrollers](http://savannah.nongnu.org/projects/avrdude/)
5. Microchip, [AVR 8-bit Toolchain for Windows, Linux, Mac OS X](https://www.microchip.com/mplab/avr-support/avr-and-arm-toolchains-c-compilers)
6. [Atom text editor](https://atom.io/)
7. [Visual Studio Code](https://code.visualstudio.com/)
8. [Doxygen, a standard tool for generating documentation from annotated source files](http://doxygen.nl/)
9. [Graphviz, open source graph visualization software](http://graphviz.org/)
10. Peter Fleury, [AVR-GCC libraries](http://homepage.hispeed.ch/peterfleury/avr-software.html)
11. Saleae, [Saleae logic analyser](https://www.saleae.com/downloads/)
12. Wykys, [Tools for development of AVR microcontrollers](https://github.com/wykys/AVR-tools)


## License

[MIT](https://choosealicense.com/licenses/mit/)

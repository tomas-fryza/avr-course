# Digital electronics 2

The repository contains AVR lab exercises for bachelor course [*Digital Electronics 2*](https://www.vutbr.cz/en/students/courses/detail/224132) at Brno University of Technology, Czechia.

## Exercises

* [Git version-control system, AVR toolchain](Labs/01-intro)
* Control of GPIO, LED, push button
* Creation of user library for GPIO control
* Interrupts, Timers
* Display devices, 7-segment display
* Display devices, LCD display
* ADC, serial communication, UART
* Serial communication, I2C/TWI
* Project, general instructions


## Materials

The following hardware and software components are mainly used in the lab.

### Hardware

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


### Software

| **Component** | **Description** | **Manual** |
| :-: | :-- | :-: |
| [VS Code](https://code.visualstudio.com/) | Visual Studio Code |
| [Saleae](https://www.saleae.com/downloads/) | Saleae logic analyser |


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

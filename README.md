[![university](https://img.shields.io/badge/university-Brno%20University%20of%20Technology-red.svg)](https://www.vutbr.cz/en/)
[![faculty](https://img.shields.io/badge/faculty-Faculty%20of%20Electrical%20Engineering%20and%20Communication-blue.svg)](https://www.fekt.vutbr.cz/)

# Digital electronics

#### Table of Contents

1. [Introduction](#introduction)
2. [Hardware Components](#hardware-components)
3. [How to Use AVR Template on Linux](docs/HOWTO_linux.md)
4. [References](#references)


## Introduction

The repository contains AVR template for bachelor course *Digital Electronics 2* ([Winter 2019/2020](https://www.vutbr.cz/en/students/courses/detail/210896)) at Brno University of Technology, Czechia.

```bash
.
├── docs
│   └── hw
├── LICENSE
├── projects
│   ├── 01-demo
│   ├── 09-asm_random
│   ├── library
│   │   ├── inc
│   │   └── src
│   └── projects.in
└── README.md
```

In folder `docs` all manuals are stored. Folder `hw` contains KiCad schematic of Arduino shields used in the course. All projects are located within `projects` folder. The `01-demo` example contains default C-code source file `main.c`, `README.md`, and `Makefile`. Default example of ASM source file `rand.S` is located in the `09-asm_random` folder. Source and header files of LCD, TWI, and UART libraries are located in the `library` folder.


## Hardware Components

The following hardware components are mainly used in the lab.

| **Component** | **Description** | **Manual** |
| ------------- | --------------- | ---------- |
| [ATmega328P](https://www.microchip.com/wwwproducts/en/ATmega328P) | 8-bit microcontroller | [Instruction set](https://www.microchip.com/webdoc/avrassembler/avrassembler.wb_instruction_list.html)
| [Arduino Uno board](https://arduino-shop.cz/arduino/1353-klon-arduino-uno-r3-atmega328p-ch340-mini-usb-1466635561.html) | Low-cost clone of Arduino UNO R3 CH340 mini USB | [Schematic](docs/hw/arduino_shield.pdf)
| [Breadboard](https://www.gme.cz/nepajive-kontaktni-pole-zy-60) | 300-pin breadboard |
| [Male-male wires](https://arduino-shop.cz/arduino/1063-arduino-vodice-samec-samec-40-kusu-1500635966.html) | Wires for interconnections |
| [Logic analyzer](https://www.ebay.com/sch/i.html?LH_CAds=&_ex_kw=&_fpos=&_fspt=1&_mPrRngCbx=1&_nkw=24mhz%20logic%20analyzer&_sacat=&_sadis=&_sop=12&_udhi=&_udlo=) | 24MHz 8-channel logic analyzer | [Software](https://www.saleae.com/)
| [Multi-function shield](https://www.gme.cz/experiment-shield-pro-arduino) | Multi-function shield with four LEDs, three push buttons, four seven-segment displays, and others | [Schematic](docs/hw/arduino_shield.pdf)
| [Arduino LCD Shield](https://arduino-shop.cz/en/arduino-platform/899-arduino-lcd-shield-1420670167.html) | LCD and keypad shield with LCD and five push buttons | [Schematic](docs/hw/arduino_shield.pdf)
| [DHT12](https://arduino-shop.cz/arduino/1977-i2c-teplomer-a-vlhkomer-dht12-digitalni.html) | I2C humidity and temperature sensor | [Data sheet](docs/dht12_manual.pdf)
| [DS3231](https://arduino-shop.cz/hledani.php?q=DS3231&n_q=) | I2C real time clock | [Data sheet](docs/ds3231_manual.pdf)
| [ESP8266](https://arduino-shop.cz/arduino/911-internet-veci-je-tady-tcp-ip-wifi-esp8266-1420990568.html) | Wi-Fi module | [AT commands](docs/esp8266_at_instruction_set.pdf)
| tbd | tbd | tbd


## References

1. [Git, free and open source distributed version control system](https://git-scm.com/)
2. [GNU Make tool for Linux](https://www.gnu.org/software/make/)
3. [Minimalist GNU for Windows](http://www.mingw.org/wiki/Getting_Started/)
4. [AVRDUDE, software for programming Atmel AVR Microcontrollers](http://savannah.nongnu.org/projects/avrdude/)
5. Microchip, [AVR 8-bit Toolchain for Windows, Linux, Mac OS X](https://www.microchip.com/mplab/avr-support/avr-and-arm-toolchains-c-compilers)
6. [Atom text editor](https://atom.io/)
7. [Doxygen, a standard tool for generating documentation from annotated source files](http://doxygen.nl/)
8. [Graphviz, open source graph visualization software](http://graphviz.org/)
9. Peter Fleury, [AVR-GCC libraries](http://homepage.hispeed.ch/peterfleury/avr-software.html)
10. Wykys, [Tools for development of AVR microcontrollers](https://github.com/wykys/AVR-tools)

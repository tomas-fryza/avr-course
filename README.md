[![university](https://img.shields.io/badge/university-Brno%20University%20of%20Technology-red.svg)](https://www.vutbr.cz/en/)
[![department](https://img.shields.io/badge/department-Dept.%20of%20Radio%20Electronics-blue)](https://www.facebook.com/URELBrno)

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
| [Arduino Nano board](https://store.arduino.cc/arduino-nano) | Arduino Nano |
| [Raspberry Pi 3](https://www.raspberrypi.org/products/raspberry-pi-3-model-b-plus/) | Raspberry Pi 3 Model B+ |
| [Breadboard](https://www.gme.cz/nepajive-kontaktni-pole-zy-60) | 300-pin breadboard |
| [Male-male wires](https://arduino-shop.cz/arduino/1063-arduino-vodice-samec-samec-40-kusu-1500635966.html) | Wires for interconnections |
| [Logic analyzer](https://www.ebay.com/sch/i.html?LH_CAds=&_ex_kw=&_fpos=&_fspt=1&_mPrRngCbx=1&_nkw=24mhz%20logic%20analyzer&_sacat=&_sadis=&_sop=12&_udhi=&_udlo=) | 24MHz 8-channel logic analyzer | [Software](https://www.saleae.com/)
| [Multi-function shield](https://www.gme.cz/experiment-shield-pro-arduino) | Multi-function shield with four LEDs, three push buttons, four seven-segment displays, and others | [Schematic](docs/hw/arduino_shield.pdf)
| [Arduino LCD Shield](https://arduino-shop.cz/en/arduino-platform/899-arduino-lcd-shield-1420670167.html) | LCD and keypad shield with LCD and five push buttons | [Schematic](docs/hw/arduino_shield.pdf)
| [Nokia display](https://arduino-shop.cz/arduino/878-arduino-lcd-display-nokia-5110-modre-podsviceni.html) | LCD display Nokia 5110, blue LED |
| [LED display Yellow](https://arduino-shop.cz/arduino/3069-hodinovy-led-displej-0.56-tm1637-zluty.html) | LED display 0.56" TM1637 yellow |
| [LED display Green](https://arduino-shop.cz/arduino/3070-hodinovy-led-displej-0.56-tm1637-zeleny.html) | LED display 0.56" TM1637 green |
| [LED display Red](https://arduino-shop.cz/arduino/3072-hodinovy-led-displej-0.56-tm1637-cerveny.html) | LED display 0.56" TM1637 red |
| [Nixie tubes Z 573 M](http://www.tube-tester.com/sites/nixie/data/z573m/z573m.htm) | Nixie tubes with digits 0, 1, ..., 9 |
| [Nixie tube Z 5810 M](http://www.tube-tester.com/sites/nixie/data/z5810m/z5810m.htm) | Nixie tube with sumbols A, Hz, F, H, Q, S, Ohm, V |
| [Nixie tube Z 5800 M](http://www.tube-tester.com/sites/nixie/data/z5800m.htm) | Nixie tube with symbols M p, n, u, m, k, M, G, T |
| [DHT12](https://arduino-shop.cz/arduino/1977-i2c-teplomer-a-vlhkomer-dht12-digitalni.html) | I2C humidity and temperature sensor | [Data sheet](docs/dht12_manual.pdf)
| [DS3231](https://arduino-shop.cz/hledani.php?q=DS3231&n_q=) | I2C real time clock | [Data sheet](docs/ds3231_manual.pdf)
| [Ultrasonic HC-SR04](https://components101.com/ultrasonic-sensor-working-pinout-datasheet) | HC-SR04 ultrasonic sensor)
| [Current sensor 5A](https://arduino-shop.cz/arduino/1072-arduino-5a-proudovy-senzor-acs712.html) | Current sensor module 5A with ACS712ELC-05B chip |
| [Current sensor 20A](https://arduino-shop.cz/arduino/1222-arduino-proudovy-senzor-20a-modul-acs712.html) | Current sensor module 20A with ACS712ELC-20A chip |
| [Gyroscope + accelerometer](https://arduino-shop.cz/arduino/830-arduino-gyroskop-akcelerometr.html) | I2C three-axis gyroscope + three-axis accelerometer with chip MPU-6050 |
| [ESP8266](https://arduino-shop.cz/arduino/911-internet-veci-je-tady-tcp-ip-wifi-esp8266-1420990568.html) | Wi-Fi module | [AT commands](docs/esp8266_at_instruction_set.pdf)
| [Bluetooth module](https://arduino-shop.cz/arduino/1312-arduino-android-ios-hm-10-bluetooth-4-0-ble-cc2540-cc2541-seriovy-bezdratovy-modul.html) | Bluetooth module HM-10 |
| [Joystick PS2](https://arduino-shop.cz/arduino/884-arduino-joystick-ps2.html) | Analog Joystick PS2 |
| [Rotary encoder](https://arduino-shop.cz/arduino/837-arduino-rotacni-enkoder.html) | Rotary encoder |
| [Micro servo](https://arduino-shop.cz/arduino/897-arduino-servo-motor.html) | Micro servo SG90 |
| [R3 Relay Shield](https://arduino-shop.cz/arduino/5003-arduino-rele-shield-2.html) | Arduino UNO R3 Relay Shield |
| [Relay shield](https://arduino-shop.cz/arduino/904-arduino-rele-shield.html) | Arduino relay shield |
| [Relay 2 channels](https://arduino-shop.cz/arduino/834-arduino-rele-2-kanaly.html) | Relay 2 channels |
| [Relay 1 channel](https://arduino-shop.cz/arduino/2954-modul-rele-5v-1-kanal-opticky-oddeleno.html) | Relay 1 channel |
| PA6H GPS | PA6H GPS module from drotek.fr |
| [Soil moisture sensor](https://arduino-shop.cz/arduino/4875-analogovy-snimac-vlhkosti-pudy-v1.2.html) | Capacitive soil moisture sensor v1.2 |
| [RGB LED](https://arduino-shop.cz/arduino/1036-led-dioda-rgb-5mm.html) | RGB LED 5mm |
| [Photoresistor](https://www.kth.se/social/files/54ef17dbf27654753f437c56/GL5537.pdf) | GL5539 photoresistor |
| [Infra LED](https://arduino-shop.cz/arduino/1137-ir-led-940nm-vysilac.html) | Infra LED 940nm |
| [Infrared receiver](https://www.hwkitchen.cz/user/related_files/infrared-prijimac-1838b.pdf) | Infrared receiver VS1838B |


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
11. Wykys, [Tools for development of AVR microcontrollers](https://github.com/wykys/AVR-tools)

# Digital electronics 2

The repository contains AVR lab exercises for bachelor course [*Digital Electronics 2*](https://www.vut.cz/en/students/courses/detail/258370) at Brno University of Technology, Czechia. [Arduino Uno and some shields](https://oshwlab.com/tomas.fryza/arduino-shields) are used as the main programming platform.

## Exercises

1. [Git version-control system, AVR tools](labs/01-tools)
2. [Control of GPIO pins](labs/02-gpio)
3. [Timers](labs/03-interrupts)
4. [Liquid Crystal Display (LCD)](labs/04-lcd)
5. [Analog-to-Digital Converter (ADC)](labs/05-adc)
6. [Universal Asynchronous Receiver-Transmitter (UART)](labs/06-uart)
7. [Inter-Integrated Circuits (I2C)](labs/07-i2c)

<!--
9. [C project: General instructions](labs/project)
10. (Self-study) [Combining C and assembly language](labs/09-asm)
-->

## List of examples

* [Basic C template, blink a LED](examples/blink_arduino/)
* [Project documentation with Doxygen](examples/doxygen)
* [Autonomous slot car](examples/slot-car)

## Components

The following hardware and software components are mainly used in the lab.

* Devices:
  * [ATmega328P](https://www.microchip.com/wwwproducts/en/ATmega328P) 8-bit microcontroller: [instruction set](https://www.microchip.com/webdoc/avrassembler/avrassembler.wb_instruction_list.html)

* Boards and shields:
  * [Schematics](https://oshwlab.com/tomas.fryza/arduino-shields)
  * [Arduino Uno](https://arduino-shop.cz/arduino/1353-klon-arduino-uno-r3-atmega328p-ch340-mini-usb-1466635561.html) board
  * [LCD and keypad shield](https://arduino-shop.cz/en/arduino-platform/899-arduino-lcd-shield-1420670167.html) with LCD and five push buttons
  * [Multi-function shield](https://www.gme.cz/experiment-shield-pro-arduino) with four LEDs, three push buttons, four seven-segment displays, and others

* Sensors and modules:
  * [DHT12](https://arduino-shop.cz/arduino/1977-i2c-teplomer-a-vlhkomer-dht12-digitalni.html) I2C humidity and temperature sensor: [data sheet](docs/dht12_manual.pdf)
  * [DS3231](https://arduino-shop.cz/hledani.php?q=DS3231&n_q=) I2C real time clock: [data sheet](docs/ds3231_manual.pdf)
  * [HC-SR04](https://components101.com/ultrasonic-sensor-working-pinout-datasheet) ultrasonic sensor
  * Analog [joystick PS2](https://arduino-shop.cz/arduino/884-arduino-joystick-ps2.html)
  * [ESP8266](https://arduino-shop.cz/arduino/911-internet-veci-je-tady-tcp-ip-wifi-esp8266-1420990568.html) Wi-Fi module: [AT commands](docs/esp8266_at_instruction_set.pdf)

* Analyzers:
  * 24MHz 8-channel [logic analyzer](https://www.ebay.com/sch/i.html?LH_CAds=&_ex_kw=&_fpos=&_fspt=1&_mPrRngCbx=1&_nkw=24mhz%20logic%20analyzer&_sacat=&_sadis=&_sop=12&_udhi=&_udlo=): [software](https://www.saleae.com/)
  * Oscilloscope Keysight Technologies [DSOX3034T](https://www.keysight.com/en/pdx-x202175-pn-DSOX3034T/oscilloscope-350-mhz-4-analog-channels?&cc=CZ&lc=eng) (350 MHz, 4 analog channels), including 16 logic timing channels [DSOXT3MSO](https://www.keysight.com/en/pdx-x205238-pn-DSOXT3MSO/3000t-x-series-oscilloscope-mso-upgrade?cc=CZ&lc=eng) and serial protocol triggering and decode options [D3000BDLA](https://www.keysight.com/en/pd-2990560-pn-D3000BDLA/ultimate-software-bundle-for-the-3000a-t-x-series?&cc=CZ&lc=eng)

* Development tools:
  * [Visual Studio Code](https://code.visualstudio.com/)
  * [PlatformIO](https://platformio.org/)
  * [Atmel Studio 7 (Microchip Studio 7)](https://www.microchip.com/en-us/development-tools-tools-and-software/microchip-studio-for-avr-and-sam-devices)
  * [GCC Compilers for AVR](https://www.microchip.com/en-us/development-tools-tools-and-software/gcc-compilers-avr-and-arm#)

* Other tools:
  * [SimulIDE](https://www.simulide.com/p/home.html), real time electronic circuit simulator. With PIC, AVR and Arduino simulation
  * [git](https://git-scm.com/)

## References

1. [How to use AVR template with PlatformIO](https://github.com/tomas-fryza/digital-electronics-2/wiki/How-to-use-AVR-template-with-PlatformIO)
2. [How to use AVR template on Windows](https://github.com/tomas-fryza/digital-electronics-2/wiki/How-to-use-AVR-template-on-Windows)
3. [How to use AVR template on Linux](https://github.com/tomas-fryza/digital-electronics-2/wiki/How-to-use-AVR-template-on-Linux)
4. Peter Fleury, [AVR-GCC libraries](http://www.peterfleury.epizy.com/avr-software.html?i=1)
5. Wykys, [Tools for development of AVR microcontrollers](https://github.com/wykys/AVR-tools)
6. Barr Group, [Embedded C Coding Standard](https://barrgroup.com/Embedded-Systems/Books/Embedded-C-Coding-Standard)

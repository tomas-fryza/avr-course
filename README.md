# Digital electronics 2

The repository contains AVR lab exercises for bachelor course [*Digital Electronics 2*](https://www.vut.cz/en/students/courses/detail/268611) at Brno University of Technology, Czechia. [Arduino Uno board and some shields](https://oshwlab.com/tomas.fryza/arduino-shields) are used as the main programming platform.

![avr_course](labs/07-i2c/images/arduino_uno_i2c.jpg)

## Exercises

1. [Git version-control system, AVR tools](labs/01-tools)
2. [Control of GPIO pins](labs/02-gpio)
3. [Timers](labs/03-interrupts)
4. [Liquid Crystal Display (LCD)](labs/04-lcd)
5. [Universal Asynchronous Receiver-Transmitter (UART)](labs/06-uart)
6. [Inter-Integrated Circuits (I2C)](labs/06-i2c)
7. [Analog-to-Digital Converter (ADC)](labs/05-adc)
8. [Assembly language and project documentation](labs/08-asm)

## List of examples

* [Basic C template, blink a LED](examples/blink_arduino/)
* [Project documentation with Doxygen](examples/doxygen)
* [Autonomous slot car](examples/slot-car)

## Components

The following hardware and software components are mainly used in the lab.

| **Component** | **Link(s)** |
| :-- | :-- |
| ATmega328P microcontroler | [data sheet](https://www.microchip.com/wwwproducts/en/ATmega328P), [instruction set](https://onlinedocs.microchip.com/pr/GUID-0B644D8F-67E7-49E6-82C9-1B2B9ABE6A0D-en-US-19/index.html)
| Arduino Uno board | [schematic](https://oshwlab.com/tomas.fryza/arduino-shields)
| LCD and keypad shield | [schematic](https://oshwlab.com/tomas.fryza/arduino-shields)
| Multi-function shield | [schematic](https://oshwlab.com/tomas.fryza/arduino-shields)
| DHT12 | I2C humidity and temperature sensor: [data sheet](docs/dht12_manual.pdf) |
| MPU6050 | I2C gyroscope and accelerometer: [data sheet](docs/dht12_manual.pdf) |
| DS3231 | I2C real time clock: [data sheet](docs/ds3231_manual.pdf) |
| HC-SR04 | ultrasonic sensor: [datasheet](https://components101.com/ultrasonic-sensor-working-pinout-datasheet) |
| Joystick PS2 | Analog [joystick PS2](https://arduino-shop.cz/arduino/884-arduino-joystick-ps2.html)
| ESP8266 Wi-Fi module | [AT commands](docs/esp8266_at_instruction_set.pdf)
| Logic analyzer | 24MHz 8-channel [logic analyzer](https://www.ebay.com/sch/i.html?LH_CAds=&_ex_kw=&_fpos=&_fspt=1&_mPrRngCbx=1&_nkw=24mhz%20logic%20analyzer&_sacat=&_sadis=&_sop=12&_udhi=&_udlo=): [software](https://www.saleae.com/)
| Osciloscope DSOX3034T | Oscilloscope Keysight Technologies [DSOX3034T](https://www.keysight.com/en/pdx-x202175-pn-DSOX3034T/oscilloscope-350-mhz-4-analog-channels?&cc=CZ&lc=eng) (350 MHz, 4 analog channels), including 16 logic timing channels [DSOXT3MSO](https://www.keysight.com/en/pdx-x205238-pn-DSOXT3MSO/3000t-x-series-oscilloscope-mso-upgrade?cc=CZ&lc=eng) and serial protocol triggering and decode options [D3000BDLA](https://www.keysight.com/en/pd-2990560-pn-D3000BDLA/ultimate-software-bundle-for-the-3000a-t-x-series?&cc=CZ&lc=eng) |
| Visual Studio Code | [web page](https://code.visualstudio.com/) |
| PlatformIO | [web page](https://platformio.org/)
| GCC Compilers for AVR | [web page](https://www.microchip.com/en-us/development-tools-tools-and-software/gcc-compilers-avr-and-arm#)
| SimulIDE | Real time electronic circuit simulator. With PIC, AVR and Arduino simulation: [web page](https://www.simulide.com/p/home.html)
| Git | [git](https://git-scm.com/) |

## References

1. [How to use AVR template with PlatformIO](https://github.com/tomas-fryza/digital-electronics-2/wiki/How-to-use-AVR-template-with-PlatformIO)
2. [How to use AVR template on Windows](https://github.com/tomas-fryza/digital-electronics-2/wiki/How-to-use-AVR-template-on-Windows)
3. [How to use AVR template on Linux](https://github.com/tomas-fryza/digital-electronics-2/wiki/How-to-use-AVR-template-on-Linux)
4. Peter Fleury, [AVR-GCC libraries](http://www.peterfleury.epizy.com/avr-software.html?i=1)
5. Wykys, [Tools for development of AVR microcontrollers](https://github.com/wykys/AVR-tools)
6. Barr Group, [Embedded C Coding Standard](https://barrgroup.com/Embedded-Systems/Books/Embedded-C-Coding-Standard)
7. 4Geeks. [How to use Gitpod](https://4geeks.com/lesson/how-to-use-gitpod)

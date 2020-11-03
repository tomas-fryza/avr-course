# Digital electronics 2

The repository contains AVR lab exercises for bachelor course [*Digital Electronics 2*](https://www.vutbr.cz/en/students/courses/detail/224132) at Brno University of Technology, Czechia.

## Exercises

1. [Git version-control system, AVR tools](Labs/01-tools)
2. [Control of GPIO, LED, push button](Labs/02-leds)
3. [User library for GPIO control](Labs/03-gpio)
4. [Interrupts, timers](Labs/04-interrupts)
5. [Display devices, 7-segment display](Labs/05-segment)
6. [Display devices, LCD display](Labs/06-lcd)
7. ADC, serial communication, UART
8. Serial communication, I2C/TWI
9. Project instructions


## Materials

The following hardware and software components are mainly used in the lab.

### Hardware

* [ATmega328P](https://www.microchip.com/wwwproducts/en/ATmega328P) 8-bit microcontroller: [instruction set](https://www.microchip.com/webdoc/avrassembler/avrassembler.wb_instruction_list.html)
* [Arduino Uno](https://arduino-shop.cz/arduino/1353-klon-arduino-uno-r3-atmega328p-ch340-mini-usb-1466635561.html) board: [schematic](Docs/arduino_shield.pdf)
* 24MHz 8-channel [logic analyzer](https://www.ebay.com/sch/i.html?LH_CAds=&_ex_kw=&_fpos=&_fspt=1&_mPrRngCbx=1&_nkw=24mhz%20logic%20analyzer&_sacat=&_sadis=&_sop=12&_udhi=&_udlo=): [software](https://www.saleae.com/)
* [Multi-function shield](https://www.gme.cz/experiment-shield-pro-arduino) with four LEDs, three push buttons, four seven-segment displays, and others: [schematic](Docs/arduino_shield.pdf)
* [LCD and keypad hield](https://arduino-shop.cz/en/arduino-platform/899-arduino-lcd-shield-1420670167.html) with LCD and five push buttons: [schematic](Docs/arduino_shield.pdf)
* Analog [joystick PS2](https://arduino-shop.cz/arduino/884-arduino-joystick-ps2.html)
* I2C humidity and temperature sensor [DHT12](https://arduino-shop.cz/arduino/1977-i2c-teplomer-a-vlhkomer-dht12-digitalni.html): [data sheet](Docs/dht12_manual.pdf)
* I2C real time clock [DS3231](https://arduino-shop.cz/hledani.php?q=DS3231&n_q=): [data sheet](Docs/ds3231_manual.pdf)
* [HC-SR04](https://components101.com/ultrasonic-sensor-working-pinout-datasheet) ultrasonic sensor
* Oscilloscope Keysight Technologies [DSOX3034T](https://www.keysight.com/en/pdx-x202175-pn-DSOX3034T/oscilloscope-350-mhz-4-analog-channels?&cc=CZ&lc=eng) (350 MHz, 4 analog channels), including 16 logic timing channels [DSOXT3MSO](https://www.keysight.com/en/pdx-x205238-pn-DSOXT3MSO/3000t-x-series-oscilloscope-mso-upgrade?cc=CZ&lc=eng) and serial protocol triggering and decode options [D3000BDLA](https://www.keysight.com/en/pd-2990560-pn-D3000BDLA/ultimate-software-bundle-for-the-3000a-t-x-series?&cc=CZ&lc=eng)
* [ESP8266](https://arduino-shop.cz/arduino/911-internet-veci-je-tady-tcp-ip-wifi-esp8266-1420990568.html) Wi-Fi module: [AT commands](Docs/esp8266_at_instruction_set.pdf)


### Software

* [Atmel Studio 7](https://www.microchip.com/mplab/avr-support/atmel-studio-7)
* [Visual Studio Code](https://code.visualstudio.com/)
* [git](https://git-scm.com/)
* [SimulIDE](https://www.simulide.com/p/home.html), real time electronic circuit simulator. With PIC, AVR and Arduino simulation.
* [Saleae logic analyser](https://www.saleae.com/downloads/)
* [Doxygen](https://www.doxygen.nl/index.html)


## References

1. [How to use AVR template on Linux](https://github.com/tomas-fryza/Digital-electronics-2/blob/master/Docs/HOWTO_linux.md)
2. [How to use AVR template on Windows](https://github.com/tomas-fryza/Digital-electronics-2/blob/master/Docs/HOWTO_windows.md)
3. Peter Fleury, [AVR-GCC libraries](http://www.peterfleury.epizy.com/avr-software.html?i=1)
4. Wykys, [Tools for development of AVR microcontrollers](https://github.com/wykys/AVR-tools)

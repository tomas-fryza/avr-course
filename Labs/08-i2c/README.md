# Lab 8: Serial communication, I2C/TWI

#### Contents

1. [Lab prerequisites](#Lab-prerequisites)
2. [Used hardware components](#Used-hardware-components)
3. [Synchronize Git and create a new project](#Synchronize-Git-and-create-a-new-project)
4. [TWI scanner](#TWI-scanner)
5. [DHT12 temperature and humidity sensor](#DHT12-temperature-and-humidity-sensor)
6. [Clean project and synchronize git](#Clean-project-and-synchronize-git)
7. [Ideas for other tasks](#Ideas-for-other-tasks)


## Lab prerequisites

1. What is the general structure of I2C frames?

    | **Frame type** | **Frame structure**&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; | **Description**&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; |
    | :-: | :-: | :-- |
    | Address |  |  |
    | Data |  |  |

2. What frames are used in I2C communication according to the following waveforms?

    &nbsp;
    ![twi_example](../../Images/twi-dht12_temperature_decoded.png "TWI communication example")

    | **Frame #** | **Description** |
    | :-: | :-- |
    | 1 | &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; |
    | 2 |  |
    | 3 |  |
    | 4 |  |
    | 5 |  |

3. Use schematic of the [Arduino Uno](../../Docs/arduino_shield.pdf) board and find to which pins the SDA and SCL signals are connected.

    | **Signal** | **MCU pin** | **Arduino pin(s)** |
    | :-: | :-: | :-: |
    | SDA (data) |  |  |
    | SCL (clock) |  |  |


## Used hardware components

1. [ATmega328P](https://www.microchip.com/wwwproducts/en/ATmega328P) 8-bit AVR microcontroller.
2. [Arduino Uno](../../Docs/arduino_shield.pdf) board.
3. [DHT12](../../Docs/dht12_manual.pdf) I2C humidity and temperature sensor.
4. [DS3231](../../Docs/ds3231_manual.pdf) I2C real time clock.
5. 24MHz 8-channel [logic analyzer](https://www.saleae.com/).


## Synchronize Git and create a new project

1. In VS Code open your Digital-electronics-2 working directory and synchronize the contents with single git command `git pull` or sequence of two commands `git fetch` followed by `git merge`.

2. Create a new folder `Labs/08-twi_scan` and copy files from the last project.


## TWI scanner

1. Use breadboard to connect humidity/temperature DHT12 digital sensor and real time clock (RTC) device DS3231 to Arduino Uno board. Use 3.3 V voltage for both TWI modules.

2. Use header file `library/Include/twi.h` of the TWI library and add the functions' input parameters, output values, and description to the following table.

    | **Function** | **Parameter(s)** | **Description** |
    | :-: | :-: | :-- |
    | `twi_init` | None | Initialize TWI, enable internal pull-up resistors, and set SCL frequency |
    | `twi_start` |  |  |
    | `twi_write` | <br>&nbsp; |  |
    | `twi_read_ack` | <br>&nbsp; |  |
    | `twi_read_nack` | <br>&nbsp; |  |
    | `twi_stop` |  |  |

3. Use template from [teacher's GitHub](https://github.com/tomas-fryza/Digital-electronics-2/blob/master/Labs/08-twi_scan/main.c), explore the use of FSM (Finite State Machine) in the application, set Timer1 overflow to 33 msec, scan all slave addresses and transmit results via UART to PuTTY SSH Client. How many slave devices there are connected?

    &nbsp;
    ![twi_scan_fsm](../../Images/fsm_twi_scan.png "Finite State Machine of TWI scanner")

    | **Address** | **TWI device** |
    | :-: | :-: |
    |  | &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; |
    |  | &nbsp; |
    |  | &nbsp; |

4. Form the UART output of your application to a hexadecimal table view according to the following example. See [I2C-bus specification and user manual](https://www.nxp.com/docs/en/user-guide/UM10204.pdf) for reserved addresses (RA).

    ```bash
    ---TWI scanner---
         0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f
    00: RA RA RA RA RA RA RA RA -- -- -- -- -- -- -- -- 
    10: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
    20: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
    30: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
    40: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
    50: -- -- -- -- -- -- -- -- -- -- -- -- OK -- -- --
    60: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
    70: -- -- -- -- -- -- -- -- RA RA RA RA RA RA RA RA
    ```


## DHT12 temperature and humidity sensor

1. Create a new project folder `08-twi_temperature` and copy three files from `08-twi_scan` project.

2. Program an FSM application which reads data from humidity/temperature DHT12 digital sensor and sends them periodically via UART to PuTTY SSH Client. Note, according to the [DHT12 manual](../../Docs/dht12_manual.pdf), the internal DHT12 data registers have the following structure.

    | **Register address** | **Description** |
    | :-: | :-- |
    | 0x00 | Humidity integer part |
	| 0x01 | Humidity fractional part |
	| 0x02 | Temperature integer part |
	| 0x03 | Temperature fractional part |
	| 0x04 | Checksum |

3. Find out how checksum byte value is calculated.


## Clean project and synchronize git

Remove all binaries and object files from the working directory and push all local changes to your remote repository.


## Ideas for other tasks

1. Use [Fritzing](https://fritzing.org/home/) application and draw the *Breadboard view* of your project.

2. Extend the FSM application, read second/minute values from RTC DS3231 device, and send them via UART to PuTTY SSH Client. According to the [DS3231 manual](../../Docs/ds3231_manual.pdf), the internal RTC registers have the following structure.

    | **Address** | **Bit 7** | **Bits 6:4** | **Bits 3:0** |
    | :-: | :-: | :-: | :-: |
    | 0x00 | 0 | 10 Seconds | Seconds |
    | 0x01 | 0 | 10 Minutes | Minutes |
    | ... | ... | ... | ... |

3. Verify the TWI communication with logic analyzer. Find out the structure of other internal RTC registers and implement the hour-value reading process.

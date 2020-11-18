# Lab 8: I2C/TWI serial communication

### Learning objectives

The purpose of the laboratory exercise is to understand XXX

![I2C scan](Images/arduino_uno_i2c.jpg)


## Preparation tasks (done before the lab at home)

Use schematic of the [Arduino Uno](../../Docs/arduino_shield.pdf) board and find out to which pins the SDA and SCL signals are connected.

   | **Signal** | **MCU pin** | **Arduino pin(s)** |
   | :-: | :-: | :-: |
   | SDA (data)  |  |  |
   | SCL (clock) |  |  |

What is the general structure of I2C address and data frames?

   | **Frame type** | **8** | **7** | **6** | **5** | **4** | **3** | **2** | **1** | **0** | **Description**&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; |
   | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-- |
   | Address | | | | | | | | | | |
   | Data    | | | | | | | | | | |


## Part 1: Synchronize repositories and create a new folder

Run Git Bash (Windows) of Terminal (Linux), navigate to your working directory, and update local repository. Create a new working folder `Labs/08-i2c` for this exercise.


## Part 2: I2C bus

**TODO:** Description







> Let the following image shows several frames of I2C communication between ATmega328P and slave device. What circuit is it and what information was sent over the bus?
>
   &nbsp;
   ![Temperature reception from DHT12 sensor](Images/twi-dht12_temperature_decoded.png)

> This communication example contains a total of five frames. After the start condition, which is initiated by the master, the address frame is always sent. It contains a 7-bit address of the slave device, supplemented by information on whether the data will be written to the slave or read from it to the master. The ninth bit of the address frame is an acknowledgment provided by the receiving side.
>
> Here, the address is 184 (decimal), i.e. `1011100_0` in binary including R/W=0. The slave address is therefore 1011100 (0x5c) and master will write data to the slave. The slave has acknowledged the address reception, so that the communication can continue. 
>
> According to the list of [I2C addresses](https://learn.adafruit.com/i2c-addresses/the-list) the device could be humidity/temp or pressure sensor. The signals were really recorded when communicating with the humidity and temperature sensor.
>
> The data frame always follows the address one and contains eight data bits from the MSB to the LSB and is again terminated by an acknowledgment from the receiving side. Here, number `2` was writen to the sensor. According to the [sensor manual](../../Docs/dht12_manual.pdf), this is the address of register, to which the integer part of measured temperature is stored. (The following register contains its fractional part.)
>
   | **Register address** | **Description** |
   | :-: | :-- |
   | 0x00 | Humidity integer part |
   | 0x01 | Humidity fractional part |
   | 0x02 | Temperature integer part |
   | 0x03 | Temperature fractional part |
   | 0x04 | Checksum |

> After the repeated start, the same circuit address is sent on the I2C bus, but this time with the read bit R/W=1 (185, `1011100_1`). Subsequently, data frames are sent from the slave to the master until the last of them is confirmed by the NACK value. Then the master generates a stop condition on the bus and the communication is terminated.
>
> The communication in the picture therefore records the temperature transfer from the sensor, when the measured temperature is 25.3 degrees C.
>
   | **Frame #** | **Description** |
   | :-: | :-- |
   | 1 | Address frame with SLA+W = 0x5c (184) |
   | 2 | Data frame sent to the slave represents the ID of internal register |
   | 3 | Address frame with SLA+R = 0x5c (185) |
   | 4 | Data frame with integer part of temperature read from slave |
   | 5 | Data frame with fractional part of temperature read from slave|


## Part 3: I2C scanner

### Version: SimulIDE

In the SimulIDE application, use the circuits: I2C Ram (**Components > Logic > Memory > I2C Ram**), I2C to Parallel (**Components > Logic > Converters > I2C to Parallel**) and create the connection according to the following figure. Also, change **Control Code** property of all devices. These codes represent the I2C addresses of the slave circuits.

![I2C scanner circuit](Images/screenshot_simulide_i2c_scan.png)


### Version: Real hardware

Use breadboard to connect humidity/temperature DHT12 digital sensor and real time clock (RTC) device DS3231 to Arduino Uno board. Use 3.3&nbsp;V voltage for both modules.


### Version: Atmel Studio 7

Create a new GCC C Executable Project for ATmega328P within `08-i2C` working folder and copy/paste [template code](main.c) to your `main.c` source file.

In **Solution Explorer** click on the project name, then in menu **Project**, select **Add Existing Item... Shift+Alt+A** and add:
   * I2C/TWI files `twi.h`, `twi.c` from `Examples/library/include` and `Examples/library` folders,
   * UART library files `uart.h`, `uart.c` from the previous lab,
   * Timer library `timer.h` from the previous labs.


### Version: Command-line toolchain

Copy `main.c` and `Makefile` files from previous lab to `Labs/08-i2c` folder.

Copy/paste [template code](main.c) to your `08-i2c/main.c` source file.

Add the source files of I2C/TWI and UART libraries between the compiled files in `08-i2c/Makefile`.

```Makefile
# Add or comment libraries you are using in the project
#SRCS += $(LIBRARY_DIR)/lcd.c
SRCS += $(LIBRARY_DIR)/uart.c
SRCS += $(LIBRARY_DIR)/twi.c
#SRCS += $(LIBRARY_DIR)/gpio.c
#SRCS += $(LIBRARY_DIR)/segment.c
```


### All versions

Use I2C/TWI header file [`twi.h`](../library/include/twi.h) and add the functions' input parameters, output values, and description to the following table.

   | **Function** | **Parameter(s)** | **Description** |
   | :-: | :-: | :-- |
   | `twi_init` | None | Initialize TWI, enable internal pull-up resistors, and set SCL frequency |
   | `twi_start` |  |  |
   | `twi_write` | <br>&nbsp; |  |
   | `twi_read_ack` | <br>&nbsp; |  |
   | `twi_read_nack` | <br>&nbsp; |  |
   | `twi_stop` |  |  |

Explore the use of FSM (Finite State Machine) in the application' [template](main.c) and complete the Timer/Counter1 overflow routine to scan slave addresses. Transmit useful information via UART to PuTTY SSH Client.








**TODO: New figure**

   &nbsp;
   ![FSM for I2C scanner](Images/fsm_twi_scan.png)








Form the UART output of your application to a hexadecimal table according to the following figure. See [I2C-bus specification and user manual](https://www.nxp.com/docs/en/user-guide/UM10204.pdf) for reserved addresses (RA).

   ```
   Scan I2C-bus for devices:

       .0 .1 .2 .3 .4 .5 .6 .7 .8 .9 .a .b .c .d .e .f
   0.: RA RA RA RA RA RA RA RA -- -- -- -- -- -- -- --
   1.: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
   2.: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
   3.: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
   4.: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
   5.: -- -- -- -- -- -- -- 57 -- -- -- -- -- -- -- --
   6.: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
   7.: -- -- -- -- -- -- -- -- RA RA RA RA RA RA RA RA
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










## Synchronize repositories

Use [git commands](https://github.com/tomas-fryza/Digital-electronics-2/wiki/Git-useful-commands) to add, commit, and push all local changes to your remote repository. Check the repository at GitHub web page for changes.


## Experiments on your own

1. Xxx.

2. Xxx.


### Version: Real hardware

3. Extend the FSM application, read second/minute values from RTC DS3231 device, and send them via UART to PuTTY SSH Client. According to the [DS3231 manual](../../Docs/ds3231_manual.pdf), the internal RTC registers have the following structure.

   | **Address** | **Bit 7** | **Bits 6:4** | **Bits 3:0** |
   | :-: | :-: | :-: | :-: |
   | 0x00 | 0 | 10 Seconds | Seconds |
   | 0x01 | 0 | 10 Minutes | Minutes |
   | ... | ... | ... | ... |

4. Verify the TWI communication with logic analyzer. Find out the structure of other internal RTC registers and implement the hour-value reading process.


## Lab assignment

1. Preparation tasks (done before the lab at home). Submit:
   * Table with xxx.

2. I2C. Submit:
   * (Hand-drawn) picture of I2C signals when xxxx,
   * Listing of xxx.
   * Screenshot of SimulIDE circuit when "Power Circuit" is applied.

The deadline for submitting the task is the day before the next laboratory exercise. Use [BUT e-learning](https://moodle.vutbr.cz/) web page and submit a single PDF file.


## References

1. Adafruit. [List of I2C addresses](https://learn.adafruit.com/i2c-addresses/the-list)
2. Aosong. [Digital temperature DHT12](../../Docs/dht12_manual.pdf)

# Lab 5: UART (Universal Asynchronous Receiver-Transmitter)

* [Pre-Lab preparation](#preparation)
* [Part 1: Basics of UART communication](#part1)
* [Part 2: Synchronize repositories and create a new folder](#part2)
* [Part 3: Communication between Arduino board and computer](#part3)
* [Challenges](#challenges)
* [References](#references)

### Components list

* Arduino Uno board, USB cable
* Logic analyzer

### Learning objectives

After completing this lab you will be able to:

* Understand the UART communication
* Decode UART frames
* Use functions from UART library
* Use logic analyzer

The purpose of the laboratory exercise is to understand serial asynchronous communication, data frame structure and communication options using an internal USART unit.

<a name="preparation"></a>

## Pre-Lab preparation

1. Use schematic of [Arduino Uno](https://oshwlab.com/tomas.fryza/arduino-shields) board and find out on which Arduino Uno pins the UART transmitter (Tx) and receiver (Rx) are located.

2. Remind yourself, what an [ASCII table](http://www.asciitable.com/) is. What codes are defined for control characters `Esc`, `Space`, `Tab`, and `Enter`?

<a name="part1"></a>

## Part 1: Basics of UART communication

The UART (Universal Asynchronous Receiver-Transmitter) is not a communication protocol like SPI and I2C, but a physical circuit in a microcontroller, or a stand-alone integrated circuit, that translates communicated data between serial and parallel forms. It is one of the simplest and easiest method for implement and understanding.

In UART communication, two UARTs communicate directly with each other. The transmitting UART converts parallel data from a CPU into serial form, transmits it in serial to the receiving UART, which then converts the serial data back into parallel data for the receiving device. Only two wires are needed to transmit data between two UARTs. Data flows from the Tx pin of the transmitting UART to the Rx pin of the receiving UART: [link](https://www.circuitbasics.com/basics-uart-communication/), [link](https://www.analog.com/en/analog-dialogue/articles/uart-a-hardware-communication-protocol.html).

UARTs transmit data asynchronously, which means there is no external clock signal to synchronize the output of bits from the transmitting UART. Instead, timing is agreed upon in advance between both units, and special **Start** (log. 0) and 1 or 2 **Stop** (log. 1) bits are added to each data package. These bits define the beginning and end of the data packet so the receiving UART knows when to start reading the bits. In addition to the start and stop bits, the packet/frame also contains data bits and optional parity.

The amount of **data** in each packet can be set from 5 to 9 bits. If it is not otherwise stated, data is transferred least-significant bit (LSB) first.

**Parity** is a form of very simple, low-level error checking and can be Even or Odd. To produce the parity bit, add all 5-9 data bits and extend them to an even or odd number. For example, assuming parity is set to even and was added to a data byte `0110_1010`, which has an even number of 1's (4), the parity bit would be set to 0. Conversely, if the parity mode was set to odd, the parity bit would be 1.

One of the most common UART formats is called **9600 8N1**, which means 8 data bits, no parity, 1 stop bit and a symbol rate of 9600&nbsp;Bd.

![UART frame 8N1](images/uart_frame_8n1.png)

> ### Example of UART communication
>
> **Question:** Let the following image shows one frame of UART communication transmitting from the ATmega328P in 8N1 mode. What ASCII code/character does it represent? According to bit period, estimate the symbol rate.
>
> &nbsp;
> ![Timing of UART](images/uart_capture_E.png)
>
> **Answer:** 8N1 means that 8 data bits are transmitted, no parity is used, and the number of stop bits is one. Because the frame always starts with a low level start bit and the order of the data bits is from LSB to MSB, the data transmitted bu UART is therefore `0100_0101` (0x45) and according to the [ASCII](http://www.asciitable.com/) (American Standard Code for Information Interchange) table, it represents the letter `E`.
>
> The figure further shows that the bit period, i.e. the duration of one bit, is 104&nbsp;us. The symbol rate of the communication is thus 1/104e-6 = 9615, i.e. approximately 9600&nbsp;Bd.

<a name="part2"></a>

## Part 2: Synchronize repositories and create a new project

1. In your working directory, use **Source Control (Ctrl+Shift+G)** in Visual Studio Code or Git Bash (on Windows) or Terminal (on Linux) to update the local repository.

   > **Help:** Useful bash and git commands are `cd` - Change working directory. `mkdir` - Create directory. `ls` - List information about files in the current directory. `pwd` - Print the name of the current working directory. `git status` - Get state of working directory and staging area. `git pull` - Update local repository and working folder.

2. In Visual Studio Code create a new PlatformIO project `lab5-uart` for `Arduino Uno` board and change project location to your local repository folder `Documents/avr-course`.

3. IMPORTANT: Rename `LAB5-UART > src > main.cpp` file to `main.c`, ie change the extension to `.c`.

<a name="part3"></a>

## Part 3: Communication between Arduino board and computer

In the lab, we are using [UART library](http://www.peterfleury.epizy.com/avr-software.html) developed by Peter Fleury.

1. Use online manual of UART library and add input parameters and description of the following functions.

   | **Function name** | **Function parameter(s)** | **Description** | **Example** |
   | :-- | :-- | :-- | :-- |
   | `uart_init` | `UART_BAUD_SELECT(9600, F_CPU)` | Initialize UART to 8N1 and set baudrate to 9600&nbsp;Bd | `uart_init(UART_BAUD_SELECT(9600, F_CPU));` |
   | `uart_getc` | | | |
   | `uart_putc` | | | |
   | `uart_puts` | | | |

2. Copy/paste [template code](https://raw.githubusercontent.com/tomas-fryza/avr-course/master/labs/05-uart/main.c) to `LAB5-UART > src > main.c` source file.

3. Use your favorite file manager and copy `timer.h` file from the previous labs to `LAB5-UART > include` folder.

4. In PlatformIO project, create a new folder `LAB5-UART > lib > uart`. Within this folder, create two new files `uart.c` and `uart.h`.

   1. Copy/paste [library source file](https://raw.githubusercontent.com/tomas-fryza/avr-course/master/labs/library/uart.c) to `uart.c`
   2. Copy/paste [header file](https://raw.githubusercontent.com/tomas-fryza/avr-course/master/labs/library/include/uart.h) to `uart.h`

   The final project structure should look like this:

   ```c
   LAB5-UART           // PlatfomIO project
   ├── include         // Included file(s)
   │   └── timer.h
   ├── lib             // Libraries
   │   └── uart        // Peter Fleury's UART library
   │       ├── uart.c
   │       └── uart.h
   ├── src             // Source file(s)
   │   └── main.c
   ├── test            // No need this
   └── platformio.ini  // Project Configuration File
   ```

5. Go through the `main.c` file and make sure you understand each line. Build and upload the code to Arduino Uno board. What is the meaning of ASCII control characters `\r`, `\n`, and `\t`?

   Use **PlatformIO: Serial Monitor** or **PuTTY application** to receive values from Arduino board. In PuTTY, set connection type to `Serial` and check that configuration is the same as in the ATmega328P application, ie. 9600 8N1 mode. Note that, **serial line** (here COM3 on Windows) could be different. In Linux, use `dmesg` command to verify your port (such as `/dev/ttyUSB0`).

   ![PuTTY](images/screenshot_putty_type.png)
   ![PuTTY](images/screenshot_putty_config.png)

   > **Warning:** Before Arduino board re-programming process, PuTTY app must be closed!
   >
   > In SimulIDE, right click to ATmega328 package and select **Open Serial Monitor**. In this window you can receive data from the microcontroller, but also send them back.

6. Configure Timer1 to overflow four times per second and transmit UART string `Paris`.

   Connect the logic analyzer to the `Tx` wire. Launch the logic analyzer software Logic and **Start** the capture. Saleae Logic software offers a decoding feature to transform the captured signals into meaningful UART messages. Click to **+ button** in **Analyzers** part and setup **Async Serial** decoder.

   ![Logic analyzer -- Paris](images/analyzer_paris.png)

   > **Note:** To perform this analysis, you will need a logic analyzer such as [Saleae](https://www.saleae.com/) or [similar](https://www.amazon.com/KeeYees-Analyzer-Device-Channel-Arduino/dp/B07K6HXDH1/ref=sr_1_6?keywords=saleae+logic+analyzer&qid=1667214875&qu=eyJxc2MiOiI0LjIyIiwicXNhIjoiMy45NSIsInFzcCI6IjMuMDMifQ%3D%3D&sprefix=saleae+%2Caps%2C169&sr=8-6) device. Additionally, you should download and install the [Saleae Logic 1](https://support.saleae.com/logic-software/legacy-software/older-software-releases#logic-1-x-download-links) or [Saleae Logic 2](https://www.saleae.com/downloads/) software on your computer.
   >
   > You can find a comprehensive tutorial on utilizing a logic analyzer in this [video](https://www.youtube.com/watch?v=CE4-T53Bhu0).

7. Use `uart_getc` function and display the ASCII code of received character in decimal, hexadecimal, and binary. You can use Timer1 overflow handler to perform such receiver. Fill the table with selected keys.

   ```c
   ISR(TIMER1_OVF_vect)
   {
       uint8_t value;
       char string[8];  // String for converted numbers by itoa()

       // Get received data from UART
       value = uart_getc();
       if (value != '\0') {  // Data are available
           // Send received character back
           uart_putc(value);

           // Send also string with ASCII code in dec, hex, and bin

           // WRITE YOUR CODE HERE
       }
   }
   ```

   | **Char** | **Decimal** | **Hexadecimal** | **Binary** |
   | :-: | :-: | :-: | :-: |
   | `Esc` |  |  |  |
   | `Space` |  |  |  |
   | `Tab` |  |  |  |
   | `Backspace` |  |  |  |
   | `Enter` |  |  |  |
   | `0` | 48 | 0x30 | `0b0011_0000` |
   | `1` |  |  |  |
   | `2` |  |  |  |
   | `A` | 65 | 0x41 | `0b0100_0001` |
   | `B` |  |  |  |
   | `C` |  |  |  |
   | `a` | 97 | 0x61 | `0b0110_0001` |
   | `b` |  |  |  |
   | `c` |  |  |  |

8. Use [ANSI Escape Sequences](https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797) and modify color and format of transmitted strings according to the following code. Try other formatting styles.

   ```c
   /* 
    * Color/formatting sequence is prefixed with `Escape` (`\x1b` in hexadecimal,
    * \033, etc), followed by opening square bracket `[`, commands delimited by 
    * semi colon `;` and ended by `m` character.
    *
    * Examples:
    *   \x1b[1;31m  - Set style to bold, red foreground
    *               - Will send sequence of "Esc [ 1 ; 3 1 m"
    *   \x1b[4;32m  - Set underline style, green foreground
    *   \x1b[0m     - Reset all attributes
    */
   uart_puts("\x1b[4;32m");  // 4: underline style; 32: green foreground
   uart_puts("This is all Green and Underlined\r\n");
   uart_puts("\x1b[0m");     // 0: reset all attributes
   uart_puts("This is Normal text again\r\n");
   ```

   To enable ANSI color codes in PlatformOI serial monitor, add the following line to `platformio.ini` project configuration file.

   ```bash
   # Enable ANSI color codes in serial monitor
   monitor_raw = yes
   ```

9. After completing your work, ensure that you synchronize the contents of your working folder with both the local and remote repository versions. This practice guarantees that none of your changes are lost. You can achieve this by using **Source Control (Ctrl+Shift+G)** in Visual Studio Code or by utilizing Git commands.

   > **Help:** Useful git commands are `git status` - Get state of working directory and staging area. `git add` - Add new and modified files to the staging area. `git commit` - Record changes to the local repository. `git push` - Push changes to remote repository. `git pull` - Update local repository and working folder. Note that, a brief description of useful git commands can be found [here](https://github.com/tomas-fryza/avr-course/wiki/Useful-Git-commands) and detailed description of all commands is [here](https://github.com/joshnh/Git-Commands).

<a name="challenges"></a>

## Challenges

1. Use ATmega328P datasheet and find out how to change the baud rate to `115200`.

2. Program an interactive console that communicates between ATmega328P and the computer (PuTTY application) via UART. If you send command `timer?` the MCU will return the current Timer1 value back to the computer.

   > **Warning:** Keep UART strings as short as possible. But if you need to transmit a larger amount of data, it is necessary to increase the size of the transmit/receive buffer in the `uart.h` file, eg to 128.
   >
   >```c
   >/** @brief  Size of the circular receive buffer, must be power of 2
   > *
   > *  You may need to adapt this constant to your target and your application by adding
   > *  CDEFS += -DUART_RX_BUFFER_SIZE=nn to your Makefile.
   > */
   >#ifndef UART_RX_BUFFER_SIZE
   ># define UART_RX_BUFFER_SIZE 128
   >#endif
   >
   >/** @brief  Size of the circular transmit buffer, must be power of 2
   > *
   > *  You may need to adapt this constant to your target and your application by adding
   > *  CDEFS += -DUART_TX_BUFFER_SIZE=nn to your Makefile.
   > */
   >#ifndef UART_TX_BUFFER_SIZE
   ># define UART_TX_BUFFER_SIZE 128
   >#endif
   >```

3. Verify basic AT commands of Wi-Fi module ESP8266 ESP-01. Connect Wi-Fi module to Arduino Uno board according to the following instructions.

   | **ESP-01 pin** | **Arduino Uno pin** | **ESP-01 pin** | **Arduino Uno pin** |
   | :-: | :-: | :-: | :-: |
   | U0TXD | Tx (pin 1) | GND | GND |
   | CHIP_EN | 3.3V | GPIO2 | Not connected |
   | EXT_RSTB | Not connected | GPIO0 | Not connected |
   | 3.3V | 3.3V | U0RXD | Rx (pin 0) |

   ![ESP8266 interconnection](images/cv_esp8266_foto_description.jpg)

   In your code, disable interruptions by commenting `// sei();` function. The reason is the micro controller will not affect UART lines and whole communication will be done between Serial Monitor and Wi-Fi module. To use PlatfomIO Serial Monitor, add the following command to `platformio.ini` project configuration file: `monitor_speed = 115200`. Compile and upload the application. Test the following AT commands and see the module's responses. If needed, use Logic analyzer to read the response of Wi-Fi module.

   * `AT` - Check the communication with module
   * `AT+CWMODE=1` - Set the module mode
   * `AT+GMR` - Get the module version
   * `AT+CWLAPOPT=1,6` - Limit the list to `rssi` and `ssid` parameters only
   * `AT+CWLAP` - List `ssid` and `rssi` parameters of available Wi-Fi APs (takes few seconds)

   The complete list and description of all AT commands are available [here](https://github.com/tomas-fryza/avr-course/blob/master/docs/esp8266_at_instruction_set.pdf). To avoid a conflict with Wi-Fi module, remove the Tx and Rx wires when uploading the firmware and put them back after the upload is complete.

4. Program a piece of code to calculate even parity bit from received value.

   ![Flowchart for Even parity](images/flowchart_parity_algo.png)

5. Draw a timing diagram of the output from UART/USART when transmitting three character data `De2` in 4800 7O2 mode (7 data bits, odd parity, 2 stop bits, 4800&nbsp;Bd). The image can be drawn on a computer (by [WaveDrom](https://wavedrom.com/) for example) or by hand. Name all parts of timing diagram.

6. Program a software UART transmitter (emulated UART) that will be able to generate UART data on any output pin of the ATmega328P microcontroller. Let the bit rate be approximately 9600&nbsp;Bd and do not use the delay library. Also consider the possibility of calculating the parity bit. Verify the UART communication with logic analyzer or oscilloscope.

<a name="references"></a>

## References

1. Tomas Fryza. [Schematic of Arduino Uno](https://oshwlab.com/tomas.fryza/arduino-shields) board

2. [ASCII Table](http://www.asciitable.com/)

3. Circuit Basics. [Basics of UART Communication](https://www.circuitbasics.com/basics-uart-communication/)

4. Eric Peňa, Mary Grace Legaspi. [UART: A Hardware Communication Protocol Understanding Universal Asynchronous Receiver/Transmitter](https://www.analog.com/en/analog-dialogue/articles/uart-a-hardware-communication-protocol.html)

5. Peter Fleury. [UART library](http://www.peterfleury.epizy.com/avr-software.html)

6. Kolban Technical Tutorials. [ESP32 Technical Tutorials: Using a logic analyzer](https://www.youtube.com/watch?v=CE4-T53Bhu0)

7. Tomas Fryza. [Useful Git commands](https://github.com/tomas-fryza/avr-course/wiki/Useful-Git-commands)

8. Christian Petersen. [ANSI Escape Sequences](https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797)

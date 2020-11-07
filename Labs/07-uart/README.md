# Lab 7: ADC, Serial communication, UART

### Learning objectives

The purpose of the laboratory exercise is to understand analog-to-digital number conversion and the use of an internal 8-channel 10-bit AD converter. Another goal is to understand serial asynchronous communication, data frame structure and communication options using an internal USART unit.

![LCD-keypad shield](Images/arduino_uno_adc.jpg)


## Preparation tasks (done before the lab at home)

Use schematic of the [LCD keypad shield](../../Docs/arduino_shield.pdf) and find out the connection of five push buttons: Select, Left, Up, Down, and Right.

&nbsp;

&nbsp;

&nbsp;

&nbsp;

&nbsp;

&nbsp;

According to the connection, calculate the voltage value on pin PC0[A0] if one button is pressed at a time. In this case, the voltage on the pin is given by the [voltage divider](https://www.allaboutcircuits.com/tools/voltage-divider-calculator/), where resistors R3, R4, R5 and R6 are applied successively.

![Equation: Voltage divider](Images/eq_divider1.png)

![Equation: Voltage divider](Images/eq_divider2.png)

&nbsp;

![Equation: Voltage divider](Images/eq_divider3.png)

&nbsp;

![Equation: Voltage divider](Images/eq_divider4.png)

&nbsp;

![Equation: Voltage divider](Images/eq_divider5.png)

&nbsp;

Calculate the ADC values ​​for these voltages according to the following equation if reference is Vref=5V and number of bits for analog to digital conversion is n=10.

![Equation: ADC conversion](Images/eq_adc.png)

   | **Push button** | **PC0[A0] voltage** | **ADC value (calculated)** | **ADC value (measured)** |
   | :-: | :-: | :-: | :-: |
   | Right  | 0     | 0   |  |
   | Up     | 0.495 | 101 |  |
   | Down   |       |     |  |
   | Left   |       |     |  |
   | Select |       |     |  |


## Part 1: Synchronize repositories and create a new folder

Run Git Bash (Windows) of Terminal (Linux), navigate to your working directory, and update local repository. Create a new working folder `Labs/07-uart` for this exercise.


## Part 2: Analog-to-Digital Conversion











1. According to the [ATmega328P datasheet](https://www.microchip.com/wwwproducts/en/ATmega328p) which I/O registers and bits configure operations of internal ADC module (see Analog-to-Digital Converter section)?

    | **Operation** | **Code** | **Description** |
    | :-: | :-- | :-- |
    | Voltage reference | `ADMUX \|= _BV(REFS0);`<br>`ADMUX \|= _BV(REFS1) \| _BV(REFS0);` | AVcc voltage reference (5V)<br>Internal 1.1V reference&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; |
    | Analog input |  | Channel ADC0 |
    | ADC clock divider |  | Division factor = 64, fadc =<br>Division factor = 128, fadc =   |
    | ADC enable |  |  |
    | ADC interrupt enable |  |  |
    | Start conversion |  |  |
    | ADC result |  |  |


## UART communication

1. What ASCII code/character is transmitting in UART (Universal asynchronous receiver-transmitter) 8N1 mode? According to bit period (one bit duration), estimate the symbol rate.

    &nbsp;
    ![uart_example](../../Images/uart_capture_E.png "UART signal")

    | **UART mode** | **Frame structure** | **ASCII code** | **Baud rate** |
    | :-: | :-: | :-: | :-: |
    | 8N1 | &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; |  |

2. What is the meaning of ASCII control characters `\r`, `\n`, and `\b`? What codes are defined for these characters in [ASCII table](http://www.asciitable.com/)?

    | **Character** | **ASCII code** | **Description** |
    | :-: | :-: | :-- |
    | `\r` |  | &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; |
    | `\n` |  |  |
    | `\b` |  |  |

3. *In the lab, we are using [UART library](http://www.peterfleury.epizy.com/avr-software.html) developed by Peter Fleury.* Use online manual of UART library and add the input parameters (output values) and description of the functions to the following table.

    | **Function** | **Parameter(s)** | **Description** |
    | :-: | :-: | :-- |
    | `uart_init` | `UART_BAUD_SELECT(9600, F_CPU)` | Initialize UART to 8N1 and set baudrate to 9600 Bd |
    | `uart_getc` |  |  |
    | `uart_putc` |  |  |
    | `uart_puts` |  |  |

4. Use template from [teacher's GitHub](https://github.com/tomas-fryza/Digital-electronics-2/blob/master/Labs/07-uart/main.c) and configure ADC (AVcc with external capacitor voltage reference, channel ADC0, prescaler 128, enable interrupt), Timer1 (start ADC conversion every second), and UART (mode 8N1, baud rate 9600) modules.

    Read voltage level of push buttons and transmit it to UART. Use PuTTY SSH Client to receive values from Arduino board. Setup the application as follows:

    | **Category** | **Parameter** | **Value/Description** |
    | :-: | --: | :-- |
    | Session | Connection type | Serial
    | Serial | Serial line to connect to | `/dev/ttyUSB0`<br>(You can use `dmesg` Linux command to verify your port) |
    |  | Speed (baud) | 9600 |
    |  | Data bits | 8 |
    |  | Stop bits | 1 |
    |  | Parity | None |
    |  | Flow control | XON/XOFF |
    | Session | Saved Sessions | usb0 |
    |  | button Save | (Save all your settings) |
    |  | button Load | (Load your saved settings) |
    |  | button Open | Open UART connection |

    > WARNING: Before Arduino board re-programming process, PuTTY SSH Client must be closed!
    >

5. Compare measured ADC values with calculated ones. Program a routine to identify which push button was pressed according to the ADC value.


## Clean project and synchronize git

Remove all binaries and object files from the working directory and push all local changes to your remote repository.


## Ideas for other tasks

1. Use [ANSI escape sequences](https://en.wikipedia.org/wiki/ANSI_escape_code) and modify color and format of transmitted strings according to the following code. Try other formatting styles.

    ```C
    /* Color/formatting sequence always starts by "\033[" and ends by "m" strings.
    * One or more formatting codes "#", separated by ";" can be used within
    * one line, such as:
    *    \033[#m      or
    *    \033[#;#m    or
    *    \033[#;#;#m  etc. */
    uart_puts("\033[4;32m");        // 4: underline style; 32: green foreground
    uart_puts("This is all Green and Underlined.");
    uart_puts("\033[0m");           // 0: reset all attributes
    uart_puts("This is Normal text again.");
    ```

2. Program an interactive console that communicates between ATmega328P and the computer (PuTTY application) via UART. Let the main screen of the console is as follows:

    ```bash
    --- Interactive UART console ---
    1: read current Timer/counter1 value
    2: reset Timer/counter1
    > 
    ```

    After pressing the '1' key on computer keyboard, ATmega328P receives ASCII code of the key and sends the current Timer1 value back to PuTTY. After pressing the '2' key, ATmega328P resets Timer1 value, etc. Use ANSI escape sequences to highlight information within PuTTY console.

    ```C
    uint8_t c;
    ...
    
    c = uart_getc();
    if (c != '\0') {        // Data available from UART
        if (c == '1') {     // Key '1' received
            ...
        }
    }
    ```

3. Program a software UART transmitter that will be able to generate UART data on any output pin of the ATmega328P microcontroller. Let the baudrate be equal to 9600 Bd. Consider also the possibility of calculating the parity bit.

4. Verify the UART communication with logic analyzer.





## Lab assignment

1. Preparation tasks (done before the lab at home). Submit:
   * Table voltage divider values, calculated and measured ADC values for all five buttons.


## References

1. [Voltage Divider Calculator](https://www.allaboutcircuits.com/tools/voltage-divider-calculator/)

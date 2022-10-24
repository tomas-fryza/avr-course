# Lab 5: Analog-to-Digital Converter (ADC)

<!--
![LCD-keypad shield](images/arduino_uno_adc.jpg)
-->

### Learning objectives

After completing this lab you will be able to:

* Calculate the voltage divider
* Understand the analog-to-digital conversion process
* Configure and use internal ADC unit

The purpose of the laboratory exercise is to understand analog-to-digital conversion and the use of an internal 8-channel 10-bit analog-to-digital converter.

### Table of contents

* [Pre-Lab preparation](#preparation)
* [Part 1: Synchronize repositories and create a new project](#part1)
* [Part 2: Voltage divider](#part2)
* [Part 3: Analog-to-Digital Conversion](#part3)
* [Experiments on your own](#experiments)
* [Post-Lab report](#report)
* [References](#references)

<a name="preparation"></a>

## Pre-Lab preparation

1. Use schematic of the [LCD keypad shield](https://oshwlab.com/tomas.fryza/arduino-shields) and find out the connection of five push buttons: Select, Left, Up, Down, and Right.

2. Remind yourself, what a [voltage divider](https://www.allaboutcircuits.com/tools/voltage-divider-calculator/) is.

<a name="part1"></a>

## Part 1: Synchronize repositories and create a new project

1. Run Git Bash (Windows) of Terminal (Linux), navigate to your working directory, and update local repository.

   > Useful bash and git commands are: `cd` - Change working directory. `mkdir` - Create directory. `ls` - List information about files in the current directory. `pwd` - Print the name of the current working directory. `git status` - Get state of working directory and staging area. `git pull` - Update local repository and working folder.
   >

2. Run Visual Studio Code and create a new PlatformIO project `lab5-adc` for `Arduino Uno` board and change project location to your local repository folder `Documents/digital-electronics-2`.

3. IMPORTANT: Rename `LAB5-ADC > src > main.cpp` file to `main.c`, ie change the extension to `.c`.

4. Copy/paste [report template](https://raw.githubusercontent.com/tomas-fryza/digital-electronics-2/master/labs/05-adc/report.md) to your `LAB5-ADC > test > README` file. Rename this file to `README.md`, ie add the extension `.md`.

<a name="part2"></a>

## Part 2: Voltage divider

1. According to the LCD keypad shield connection, calculate the voltage values on pin PC0[A0] for each pressed buttons. In this case, the voltage on the pin is given by the [voltage divider](https://www.allaboutcircuits.com/tools/voltage-divider-calculator/), where resistors R3, R4, R5 and R6 are applied successively. Write your values to the **PC0[A0] voltage** column in the following table.

   ![voltage divider](images/voltage_divider.png)

   <!--
   ![Equation: Voltage divider](images/eq_divider1.png)

   ![Equation: Voltage divider](images/eq_divider2.png)

   ![Equation: Voltage divider](images/eq_divider3.png)
   -->

   &nbsp;

   ![Equation: Voltage divider](images/eq_divider4.png)

   &nbsp;

   ![Equation: Voltage divider](images/eq_divider5.png)

   &nbsp;

   <!--
   ![Equation: Voltage divider](images/eq_divider6.png)

   &nbsp;
   -->

   | **Push button** | **PC0[A0] voltage** | **ADC value (calculated)** | **ADC value (measured)** | **ADC value (measured, hex)** |
   | :-: | :-: | :-: | :-: | :-: |
   | Right  | 0&nbsp;V | 0   | 0 | 0 |
   | Up     | 0.495&nbsp;V | 101 |  |  |
   | Down   | 1.203&nbsp;V | 246 |  |  |
   | Left   |  |  |  |  |
   | Select |  |  |  |  |
   | none   |  |  |  |  |

   ![SimulIDE](images/screenshot_simulide_lcd_probe.png)

<a name="part3"></a>

## Part 3: Analog-to-Digital Conversion

We live in an analog world, but surrounded by digital devices. Everything we see, feel or measure is analog in nature such as light, temperature, speed, pressure etc. It is obvious that we need something that could convert these analog parameters to digital value for a microcontroller or micro-processor to understand it.

An [Analog to Digital Converter](https://components101.com/articles/analog-to-digital-adc-converters) (ADC) is a circuit that converts a continuous voltage value (analog) to a binary value (digital). These ADC circuits can be found as an individual ADC ICs by themselves or embedded into a modern microcontroller.

The internal ADC module of ATmega328P can be used in relatively slow and not extremely accurate data acquisitions. But it is a good choice in most situations, like reading sensor data or push button signals.

AVR ADC module has 10-bit resolution with +/-2LSB accuracy. It means it returns a 10-bit integer value, i.e. a range of 0 to 1023. It can convert data at up to 76.9&nbsp;kSPS, which goes down when higher resolution is used. We mentioned that there are 8 ADC channels available on pins, but there are also three internal channels that can be selected with the multiplexer decoder. These are temperature sensor (channel 8), bandgap reference (1.1V) and GND (0V) [[4]](https://embedds.com/adc-on-atmega328-part-1/).

1. Convert the voltages from the previous part according to the following equation. Note that reference is Vref=5V and number of bits for analog to digital conversion is n=10. Write the values to **ADC value (calculated)** column in the table from Part 2.1.

   &nbsp;
   
   ![Equation: ADC conversion](images/eq_adc.png)

   &nbsp;

2. The operation with the AD converter is performed through ADMUX, ADCSRA, ADCL+ADCH, ADCSRB, and DIDR0 registers. See [ATmega328P datasheet](https://www.microchip.com/wwwproducts/en/ATmega328p) (**Analog-to-Digital Converter > Register Description**) and complete the following table.

   | **Operation** | **Register(s)** | **Bit(s)** | **Description** |
   | :-- | :-: | :-: | :-- |
   | Voltage reference    | ADMUX | REFS1:0 | 00: ..., 01: AVcc voltage reference (5V), ... |
   | Input channel        | ADMUX | MUX3:0 | 0000: ADC0, 0001: ADC1, ... |
   | ADC enable           | ADCSRA |  |  |
   | Start conversion     |  |  |  |
   | ADC interrupt enable |  |  |  |
   | ADC clock prescaler  |  | ADPS2:0 | 000: Division factor 2, 001: 2, 010: 4, ...|
   | ADC 10-bit result    |  |  |  |

3. Copy/paste [template code](https://raw.githubusercontent.com/tomas-fryza/digital-electronics-2/master/labs/05-adc/main.c) to `LAB5-ADC > src > main.c` source file.

4. Use your favorite file manager and copy `timer`, `gpio`, and `lcd` libraries from the previous lab to the proper locations within the `LAB5-ADC` project. The final project structure should be as:

   ```c
   ├── include
   │   └── timer.h
   ├── lib
   │   ├── gpio
   |   │   ├── gpio.c
   |   |   └── gpio.h
   │   └── lcd
   |       ├── lcd.c
   |       ├── lcd.h
   |       └── lcd_definitions.h
   └── src
       └── main.c
   ```

5. Go through the `main.c` file and make sure you understand each line. Use ATmega328P datasheet and complete the ADC configuration as follows:

   * voltage reference: AVcc with external capacitor
   * input channel: ADC0
   * clock prescaler: 128
   * enable ADC module
   * enable interrupt

   <!--
   ![adc timing](images/timing_adc.png)
   -->

   Use single conversion mode and start the AD conversion every 33 ms by Timer/Counter1 overflow. When analog to digital conversion is finished, read the voltage level on push buttons and display it in decimal at LCD display position `a`. Display the same value in hexadecimal at position `b`. Note that you can use the 16-bit `ADC` variable (declared in the AVR library) to read the value from both converter registers ADCH:L.

   ```c
   /**********************************************************************
    * Function: ADC complete interrupt
    * Purpose:  Display converted value on LCD screen.
    **********************************************************************/
   ISR(ADC_vect)
   {
       uint16_t value;
       char string[4];  // String for converted numbers by itoa()

       // Read converted value
       // Note that, register pair ADCH and ADCL can be read as a 16-bit value ADC
       value = ADC;
       // Convert "value" to "string" and display it
   }
   ```

   Use standard C library and display converted value as string. Build the application and upload it to Arduino Uno board

   ![LCD-keypad shield](images/arduino_uno_adc.jpg)

6. Test all push buttons and write converted values to the **ADC value (measured)** column in the table from Part 2.1.

7. Apply the "extending" method from past labs and start the ADC conversion not every 33 milliseconds but every 100 milliseconds.

8. (Optional) Based on the converted values, distinguish which push button was pressed and display the information at LCD position `c`.

9. When you finish, always synchronize the contents of your working folder with the local and remote versions of your repository. This way you are sure that you will not lose any of your changes. To do that, use **Source Control (Ctrl+Shift+G)** in Visual Studio Code or git commands.

   > Useful git commands are: `git status` - Get state of working directory and staging area. `git add` - Add new and modified files to the staging area. `git commit` - Record changes to the local repository. `git push` - Push changes to remote repository. `git pull` - Update local repository and working folder. Note that, a brief description of useful git commands can be found [here](https://github.com/tomas-fryza/digital-electronics-1/wiki/Useful-Git-commands) and detailed description of all commands is [here](https://github.com/joshnh/Git-Commands).
   >

<a name="experiments"></a>

## Experiments on your own

1. Try to recalculate the input voltage values in mV. *Hint: Use integer data types only; the absolute accuracy of the calculation is not important here.*

2. Create a library for Analog-to-Digital Converter. Create new files `adc.h` and `adc.c`, suggest function names, their parameters, and program their bodies.

<a name="report"></a>

## Post-Lab report

*Complete all parts of `LAB5-ADC > test > README.md` file (see Part 1.4) in Czech, Slovak, or English, push it to your GitHub repository, and submit a link to this file via [BUT e-learning](https://moodle.vutbr.cz/). The deadline for submitting the task is the day before the next computer exercise.*

*Vypracujte všechny části ze souboru `LAB5-ADC > test > README.md` (viz Část 1.4) v českém, slovenském, nebo anglickém jazyce, uložte je na váš GitHub repozitář a odevzdejte link na tento soubor prostřednictvím [e-learningu VUT](https://moodle.vutbr.cz/). Termín odevzdání úkolu je den před dalším počítačovým cvičením.*

<a name="references"></a>

## References

1. Tomas Fryza. [Schematic of LCD Keypad shield](https://oshwlab.com/tomas.fryza/arduino-shields)

2. EETech Media, LLC. [Voltage Divider Calculator](https://www.allaboutcircuits.com/tools/voltage-divider-calculator/)

3. Components101. [Introduction to Analog to Digital Converters (ADC Converters)](https://components101.com/articles/analog-to-digital-adc-converters)

4. Embedds. [ADC on Atmega328. Part 1](https://embedds.com/adc-on-atmega328-part-1/)

5. Microchip Technology Inc. [ATmega328P datasheet](https://www.microchip.com/wwwproducts/en/ATmega328p)

6. Tomas Fryza. [Useful Git commands](https://github.com/tomas-fryza/digital-electronics-2/wiki/Useful-Git-commands)

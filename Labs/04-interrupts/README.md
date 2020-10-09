# Lab 4: Interrupts, timer

### Learning objectives

The purpose of the laboratory exercise is to understand the function of the interrupt, interrupt service routine, and the structure of the timer unit. Another goal is to master the search for information in the MCU manual; specifically setting the timer control registers.

![Multi-function shield](Images/arduino_uno_multi-shield.jpg)


## Preparation tasks (done before the lab at home)

Consider an n-bit number that we increment based on the clock signal. If we reach its maximum value and try to increment it, it will be reset. We call this state an overflow. The overflow time depends on the frequency of the clock signal, the number of bits, and on the prescaler value:

&nbsp;
![Timer overflow](Images/timer_overflow.png)
&nbsp;

Calculate the overflow times for three Timer/Counter modules that contain ATmega328P if CPU clock frequency is 16&nbsp;MHz. Complete the following table for given 5 prescaler values. Note that, Timer/Counter2 is able to set 7 prescaler values, including 32 and 128.

| **Module** | **Number of bits** | **1** | **8** | **32** | **64** | **128** | **256** | **1024** |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: |
| Timer/Counter0 | 8  | 16u | 128u | -- | | -- | | |
| Timer/Counter1 | 16 |     |      | -- | | -- | | |
| Timer/Counter2 | 8  |     |      |    | |    | | |


**TODO: What is a shield??**

See schematic of [Multi-function shield](../../Docs/arduino_shield.pdf) and find out the connection of D1, D2, D3, D4 LEDs and S1-A1, S2-A2, S3-A3 push buttons.

&nbsp;

&nbsp;

&nbsp;

&nbsp;

&nbsp;

&nbsp;


## Part 1: Synchronize repositories and create a new folder

Run Git Bash (Windows) of Terminal (Linux) and synchronize local and remote repositories. Create a new working folder `Labs/04-interrupts` for this exercise.


## Part 2: Timers

A timer (or counter) is a hardware block built in the MCU. It is like a clock, and can be used to measure time events. ATmega328P has three timers, called:
   * Timer/Counter0,
   * Timer/Counter1, and
   * Timer/Counter2.

T/C0 and T/C2 are 8-bit timers, where T/C1 is a 16-bit timer. The counter in microcontroller counts in synchronisation with microcontroller clock upto 256 (for 8-bit counter) or 65535 (for 16-bit). Different clock sources can be selected for each timer independently using the CPU frequency prescaler to divide by various prescaling numbers such as 8, 64, 256, 1024.

The timer modules can be configured with several special purpose registers. According to the [ATmega328P datasheet](https://www.microchip.com/wwwproducts/en/ATmega328p) (eg in the **8-bit Timer/Counter0 with PWM > Register Description** section), which I/O registers and which bits configure the timer operations?

| **Module** | **Operation** | **I/O register(s)** | **Bit(s)** |
| :-: | :-- | :-: | :-- |
| Timer/Counter0 | Prescaler<br><br>8-bit data value<br>Overflow interrupt enable | <br><br><br> | <br><br><br> |
| Timer/Counter1 | Prescaler<br><br>16-bit data value<br>Overflow interrupt enable | TCCR1B<br><br>TCNT1H, TCNT1L<br>TIMSK1 | CS12, CS11, CS10<br>(000: stopped, 001: 1, 010: 8, 011: 64, 100: 256, 101: 1024)<br>TCNT1[15:0]<br>TOIE1 (1: enable, 0: disable) |
| Timer/Counter2 | Prescaler<br><br>8-bit data value<br>Overflow interrupt enable | <br><br><br> | <br><br><br> |


### Version: Atmel Studio 7

Create a new GCC C Executable Project for ATmega328P within `04-interrupt` working folder and copy/paste [template code](main.c) to your `main.c` source file.

In **Solution Explorer** click on the project name, then in menu **Project**, select **Add New Item... Ctrl+Shift+A** and add a new C/C++ Include File `timer.h`. Copy/paste the [template code](../library/include/timer.h) into it.

Use **Add XXXXX Item... XXXX** twice and add both GPIO library files (`gpio.h`, `gpio.c`) from the previous lab.


### Version: Command-line toolchain

Check if `library` folder and `Makefile.in` settings file exist within `Labs` folder.

Copy `main.c` and `Makefile` files from previous lab to `Labs/04-interrupt` folder.

Copy/paste [template code](main.c) to your `04-interrupt/main.c` source file.

Create a new library header file in `Labs/library/include/timer.h` and copy/paste the [template code](../library/include/timer.h) into it.


### Both versions

For easier setting of control registers, in `timer.h` define macros with suitable names, which will ensure low-level setup. In this case, it is no longer necessary to define any functions and therefore not to create the source file `timer.c`.

```C
#ifndef TIMER_H
#define TIMER_H

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>

/* Defines -----------------------------------------------------------*/
/**
 * @brief Defines prescaler CPU frequency values for Timer/Counter1.
 * @note  F_CPU = 16 MHz
 */
#define TIM1_stop()             TCCR1B &= ~((1<<CS12) | (1<<CS11) | (1<<CS10));
#define TIM1_overflow_4ms()     TCCR1B &= ~((1<<CS12) | (1<<CS11)); TCCR1B |= (1<<CS10);
#define TIM1_overflow_33ms()    TCCR1B &= ~((1<<CS12) | (1<<CS10)); TCCR1B |= (1<<CS11);
#define TIM1_overflow_262ms()   TCCR1B &= ~(1<<CS12); TCCR1B |= (1<<CS11) | (1<<CS10);
#define TIM1_overflow_1s()      TCCR1B &= ~((1<<CS11) | (1<<CS10)); TCCR1B |= (1<<CS12);
#define TIM1_overflow_4s()      TCCR1B &= ~(1<<CS11); TCCR1B |= (1<<CS12) | (1<<CS10);

/**
 * @brief Defines interrupt enable/disable modes for Timer/Counter1.
 */
#define TIM1_overflow_interrupt_enable()    TIMSK1 |= (1<<TOIE1);
#define TIM1_overflow_interrupt_disable()   TIMSK1 &= ~(1<<TOIE1);

#endif
```


## Part 3: Polling and Interrupts

The state of continuous monitoring is known as **polling**. The microcontroller keeps checking the status of other devices; and while doing so, it does no other operation and consumes all its processing time for monitoring [[1]](https://www.renesas.com/us/en/support/technical-resources/engineer-school/mcu-programming-peripherals-04-interrupts.html).

While polling is a simple way to check for state changes, there's a cost. If the checking interval is too long, there can be a long lag between occurrence and detection and you may miss the change completely, if the state changes back before you check. A shorter interval will get faster and more reliable detection, but also consumes much more processing time and power, since many more checks will come back negative.

An alternative approach is to utilize **interrupts**. With this method, the state change generates an interrupt signal that causes the CPU to suspend its current operation (and save its current state), then execute the processing associated with the interrupt, and then restore its previous state and resume where it left off.

![Interrupts versus polling](Images/interrupts_vs_polling.jpg)

An interrupt is one of the fundamental features in a microcontroller. It is a signal to the processor emitted by hardware or software indicating an event that needs immediate attention. Whenever an interrupt occurs, the controller completes the execution of the current instruction and starts the execution of an **Interrupt Service Routine (ISR)** or Interrupt Handler. ISR tells the processor or controller what to do when the interrupt occurs [[2]](https://www.tutorialspoint.com/embedded_systems/es_interrupts.htm). After the interrupt code is executed, the program continues exactly where it left off.

Interrupts can be established for events such as a counter's number, a pin changing state, serial communication receiving of information, or the Analog to Digital Converted has finished the conversion process.

See the [ATmega328P datasheet](https://www.microchip.com/wwwproducts/en/ATmega328p) (**Interrupts** section) for sources of interruptions that can occur on ATmega328P. Complete the selected interrupt sources in the following table. The names of the interrupt vectors in C can be found in [C library manual](https://www.nongnu.org/avr-libc/user-manual/group__avr__interrupts.html).

| **Program address** | **Source** | **Vector name** | **Description** |
| :-: | :-- | :-- | :-- |
| 0x0000 | RESET | -- | Reset of the system |
| 0x0002 | INT0  | `INT0_vect`&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; | External interrupt request number 0 |
|  | INT1 |  |  |
|  | PCINT0 |  |  |
|  | PCINT1 |  |  |
|  | PCINT2 |  |  |
|  | TIMER2_OVF |  |  |
|  | TIMER1_OVF |  |  |
|  | TIMER0_OVF |  |  |
|  | ADC |  |  |
|  | TWI |  |  |

All interrupts are disabled by default. If you want to use them, you must first enable them individually in specific control registers and then enable them centrally with the `sei()` command (Set interrupt). You can also centrally disable all interrupts with the `cli()` command (Clear interrupt).


## Part 4: Final application

In `04-interrupts/main.c` file, rewrite the application for flashing LEDs, but this time without using the `delay.h` library.

Use Multi-function shield and toggle three LEDS by internal Timer/Counter0, Timer/Counter1, and Timer/Counter2 with different overflow times. Do not forget to include both gpio abs timer header files to your main application `#include "gpio.h"` and `#include "timer.h"`.

In addition, if you want to use interrupts in your application, you must:
   * insert the header file `#include <avr/interrupt.h>`,
   * make peripheral function settings,
   * define interrupt handlers such as `ISR(TIMER1_OVF_vect)`, and
   * allow such handlers to run by `sei()` macro.


```C
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
...

int main(void)
{
    ...

    // Enables interrupts by setting the global interrupt mask
    sei();

    // Infinite loop
    while (1)
    {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines ISRs */
    }

    // Will never reach this
    return 0;
}

ISR(TIMER1_OVF_vect)
{
    // WRITE YOUR CODE HERE
}
```

Compile the code and download to Arduino Uno board or load `*.hex` firmware to SimulIDE circuit (follow the connection according to the Multi-function shield).

Observe the correct function of the application on the flashing LEDs or measure them using a logic analyzer. Try different overflow times for each counter.


## Synchronize repositories

Use [git commands](https://github.com/tomas-fryza/Digital-electronics-2/wiki/Git-useful-commands) to add, commit, and push all local changes to your remote repository. Check the repository at GitHub web page for changes.


## Experiments on your own

1. **TBD...**











1. Use the [ATmega328P datasheet](https://www.microchip.com/wwwproducts/en/ATmega328p) and configure Timer/Counter1 to generate a PWM (Pulse Width Modulation) signal on channel A (pin PB1, OC1A). Configure Fast PWM, 10-bit, and non-inverting mode to control a LED at pin PB1. Select the 64 clock prescaler. Increment the duty cycle when the timer overflows, ie each PWM signal period. Note: The 16-bit value of the output compare register pair OCR1AH:L is directly accessible using the OCR1A variable defined in the AVR Libc library.

2. Use basic [Goxygen commands](http://www.doxygen.nl/manual/docblocks.html#specialblock) inside C-code comments and prepare your `timer.h` library for easy PDF manual generation.

3. Create a new function using the external and timer interrupts to debounce a push button signal.


## Lab assignment

**TBD...**

1. Preparation tasks (done before the lab at home). Submit:
    * Table with overflow times.

2. Timer library. Submit:
    * Table with Timers control registers and bits,
    * Listing of library header file `timer.h`,
    * C code of the application `main.c`,
    * Screenshot of SimulIDE circuit.
    * In your words, describe the difference between a common C function and interrupt service routine.

The deadline for submitting the task is the day before the next laboratory exercise. Use [BUT e-learning](https://moodle.vutbr.cz/) web page and submit a single PDF file.

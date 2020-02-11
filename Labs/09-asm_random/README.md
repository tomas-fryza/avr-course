# Lab 9: Combining C and assembly source files

#### Contents

1. [Lab prerequisites](#Lab-prerequisites)
2. [Used hardware components](#Used-hardware-components)
3. [Synchronize Git and create a new project](#Synchronize-Git-and-create-a-new-project)
4. [LFSR-based pseudo random generator](#LFSR-based-pseudo-random-generator)
5. [Variable-length burst generator](#Variable-length-burst-generator)
6. [Clean project and synchronize git](#Clean-project-and-synchronize-git)
7. [Ideas for other tasks](#Ideas-for-other-tasks)


## Lab prerequisites

1. How many *working* (General Purpose) registers does the AVR microcontroller contain? What are their names?

2. Using [AVR assembler instruction](https://www.microchip.com/webdoc/avrassembler/avrassembler.wb_instruction_list.html) set manual, find the description of selected instructions, and complete the table.

    | **Instruction** | **Operation** | **Description** | **Cycles** |
    | :-- | :-: | :-- | :-: |
    | `add Rd, Rr` | Rd = Rd + Rr | Adds two registers without Carry flag | 1 |
    | `andi Rd, K` | Rd = Rd and K | Logical AND between register Rd and 8-bit constant K | 1 |
    | `brne k` |  |  |  |
    | `bst Rd, b` |  |  |  |
    | `eor Rd, Re` |  |  |  |
    | `ldi Rd, K` |  |  |  |
    | `lsl Rd` |  |  |  |
    | `mov Rd, Rr` |  |  |  |
    | `out A, Rr` |  |  |  |
    | `push Rr` |  |  |  |
    | `rcall k` |  |  |  |
    | `rjmp k` |  |  |  |
    | `sbi A, b` |  |  |  |
    | `nop` |  |  |  |


## Used hardware components

1. [ATmega328P](https://www.microchip.com/wwwproducts/en/ATmega328P) 8-bit AVR microcontroller.
2. [Arduino Uno](../../Docs/arduino_shield.pdf) board.
3. 24MHz 8-channel [logic analyzer](https://www.saleae.com/).


## Synchronize Git and create a new project

1. In VS Code open your Digital-electronics-2 working directory and synchronize the contents with single git command `git pull` or sequence of two commands `git fetch` followed by `git merge`.

2. Create a new folder `Labs/09-asm_random` and copy files from the last project.


## LFSR-based pseudo random generator

1. Create a new source file [09-asm_random/rand.S](https://github.com/tomas-fryza/Digital-electronics-2/blob/master/Labs/09-asm_random/rand.S), use template from [teacher's GitHub](https://github.com/tomas-fryza/Digital-electronics-2/blob/master/Labs/09-asm_random/main.c), explore the use of FSM in the application, set Timer1 overflow to 33 msec, generate pseudo-random sequences, and transmit results via UART to PuTTY SSH Client.

2. Verify that feedback taps generate the maximum-length LFSR (Linear-feedback shift register) sequence for 4- and 8-bit structure.

3. Explore the LFSR algorithm within `rand4_asm` function. What the taps positions mean?

    > Use the following structure of 8-bit LFSR to derive the connection for 4-bit algorithm.
    >
    ![rand8](../../Images/lfsr.png "8-bit LFSR")

4. Use `make list` command to generate listing file `DEMO.lss` by the compiler. Check: (a) interrupt vectors (How many interrupt routines are used?), (b) body of `rand4_asm` function. Is there any pseudo-instruction?

5. With help of [AVR assembler instruction](https://www.microchip.com/webdoc/avrassembler/avrassembler.wb_instruction_list.html) set manual, convert one instruction from assembly to machine code. Verify your result with listing file.

6. Calculate the duration of `rand4_asm` function.


## Variable-length burst generator

1. Create a new project folder `09-asm_burst` and copy needed files from previous project(s).

2. In assembly, program a function `extern void burst_asm(uint8_t number)` to generate a variable number of short pulses at output pin PB5. Let the pulse width be the shortest one. Use logical analyzer, verify the pulses' width, and calculate the CPU frequency.


## Clean project and synchronize git

Remove all binaries and object files from the working directory and push all local changes to your remote repository.


## Ideas for other tasks

1. Program a 16-bit LFSR-based pseudo-random generator in assembly language and display values at UART. What LFSR taps provide the maximum length of generated sequence? 

2. In assembly, program a function to find a maximum value of input array. Transmit the result via UART.

3. In assembly, program a function to calculate the sum of product of two integer vectors. Transmit the result via UART.

4. In assembly, program your own delay function and let the parameter is duration in microseconds.

5. In assembly, program interrupt service routine for Timer1 overflow.

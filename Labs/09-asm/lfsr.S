;* ---------------------------------------------------------------------
;*
;* Assembly implementation of 4- and 8-bit LFSR-based (Linear Feedback
;* Shift Register) pseudo-random generators.
;* ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
;*
;* Copyright (c) 2017-2020 Tomas Fryza
;* Dept. of Radio Electronics, Brno University of Technology, Czechia
;* This work is licensed under the terms of the MIT license.
;*
;* https://www.xilinx.com/support/documentation/application_notes/xapp052.pdf
;* http://courses.cse.tamu.edu/walker/csce680/lfsr_table.pdf
;*
;* ---------------------------------------------------------------------

;* Includes ------------------------------------------------------------
; Set offset for control register addresses (NEEDED FOR I/O REGISTERS)
#define __SFR_OFFSET    0
#include <avr/io.h>

;* Defines -------------------------------------------------------------
#define register    r24
#define input0      r16
#define input1      r17

;* Function definitions ------------------------------------------------
;* LFSR-based 4-bit pseudo-random generator. Taps are equal to 3, 1.
;* Input:  r24 - Current value of shift register
;* Return: r24 - New value of shift register
.global rand4_asm
rand4_asm:
    push input0             ; Save used registers on Stack
    push input1

    ; register:         3   2   1   0
    ; +---+---+---+---+---+---+---+---+
    ; |   |   |   |   | 3 |   | 1 |   |
    ; +---+---+---+---+---+---+---+---+
    bst register, 3         ; Copy FIRST tap to T flag...
    bld input0, 0           ; ...and then to input0 bit 0
    ; input0:                       0
    ; +---+---+---+---+---+---+---+---+
    ; |   |   |   |   |   |   |   | 3 |
    ; +---+---+---+---+---+---+---+---+
    bst register, 1         ; Copy SECOND tap to T flag
    bld input1, 0           ; ...and then to input1 bit 0
    ; input1:                       0
    ; +---+---+---+---+---+---+---+---+
    ; |   |   |   |   |   |   |   | 1 |
    ; +---+---+---+---+---+---+---+---+
    eor input0, input1      ; Xor both taps
    com input0              ; Invert Xor
    ror input0              ; Move bit0 to C flag
    ; input0:
    ; +---+---+---+---+---+---+---+---+
    ; |   |   |   |   |   |   |   | * | --> C
    ; +---+---+---+---+---+---+---+---+
    rol register            ; Shift register left with C flag
    ; register:         3   2   1   0
    ; +---+---+---+---+---+---+---+---+
    ; |   |   |   | 3 | 2 | 1 | 0 | C | <-- C
    ; +---+---+---+---+---+---+---+---+
    andi register, 0x0f     ; Clear four upper bits in register
    ; register:         3   2   1   0
    ; +---+---+---+---+---+---+---+---+
    ; |   |   |   |   | 2 | 1 | 0 | C |
    ; +---+---+---+---+---+---+---+---+

    pop input1              ; Restore used registers from Stack
    pop input0
    ret                     ; Return from subroutine

;*----------------------------------------------------------------------
;* LFSR-based 8-bit pseudo-random generator. Taps are equal to 7, 5, 4, 3.
;* Input:  r24 - Current value of shift register
;* Return: r24 - New value of shift register
.global rand8_asm
rand8_asm:
    push input0             ; Save used registers on Stack
    push input1

    ; register: 5   4   3   2   1   0
    ; +---+---+---+---+---+---+---+---+
    ; | 7 |   | 5 | 4 | 3 |   |   |   |
    ; +---+---+---+---+---+---+---+---+
    bst register, 7         ; Xor taps 7 and 5
    bld input0, 0
    bst register, 5
    bld input1, 0
    eor input0, input1

    bst register, 4         ; Xor tap 4 with subresult in input0
    bld input1, 0
    eor input0, input1

    bst register, 3         ; Xor tap 3 with subresult in input0
    bld input1, 0
    eor input0, input1

    com input0              ; Invert Xor
    ror input0              ; Move bit0 to C flag
    rol register            ; Shift register left with C flag

    pop input1              ; Restore used registers from Stack
    pop input0
    ret                     ; Return from subroutine

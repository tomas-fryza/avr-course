;*
;* ---------------------------------------------------------------------
;* Author:      Tomas Fryza, Wykys
;*              Dept. of Radio Electronics, Brno Univ. of Technology
;* Created:     2017-11-09
;* Last update: 2019-11-15
;* Platform:    ATmega328P, 16 MHz, AVR 8-bit Toolchain 3.6.2
;* ---------------------------------------------------------------------
;* Description:
;*    Assembly implementation of 4- and 8--bit LFSR-based (Linear
;*    Feedback Shift Register) pseudo-random generators.
;*
;* Note:
;*    https://www.xilinx.com/support/documentation/application_notes/xapp052.pdf
;*    http://courses.cse.tamu.edu/walker/csce680/lfsr_table.pdf
;*

; Set offset for control register addresses (NEEDED FOR I/O REGISTERS)
#define __SFR_OFFSET 0

#include <avr/io.h>
#define result  r16
#define temp    r17
#define input   r24

;**
;*  Brief:  LFSR-based 4-bit pseudo-random generator.
;*  Input:  r24 - Current value of shift register
;*  Return: r24 - New value of shift register
;*  Note:   LFSR taps positions are: 3, 2
;*
.global rand4_asm
rand4_asm:
    push result             ; Save "Result" on Stack
    push temp               ; Save "Temp" on Stack

    bst input, 3            ; Copy "Input" bit 3 to T Flag...
    bld result, 0           ; ...and then to "Result" bit 0
    bst input, 2            ; Copy "Input" bit 2 to T Flag
    bld temp, 0             ; ...and then to "Temp" bit 0
    eor result, temp        ; Xor "Input" bits 3 and 2

    lsl input               ; Shift all "Input" bits to left
    com result              ; Invert "Result"
    bst result, 0           ; Copy "Result" bit 0 to T Flag...
    bld input, 0            ; ...and then to "Input" bit 0
    andi input, 0x0f        ; Make sure 4 upper birs are cleared

    pop temp                ; Restore "Temp" from Stack
    pop result              ; Restore "Result" from Stack
    ret                     ; Return from subroutine

;**
;*  Brief:  LFSR-based 8-bit pseudo-random generator.
;*  Input:  r24 - Current value of shift register
;*  Return: r24 - New value of shift register
;*  Note:   LFSR taps positions are: 7, 5, 4, 3
;*
.global rand8_asm
rand8_asm:
    push result             ; Backup values to Stack
    push temp

    bst input, 7            ; Xor "Input" bit 7 and 5
    bld result, 0
    bst input, 5
    bld temp, 0
    eor result, temp

    bst input, 4            ; Xor "Input" bit 4 with subresult
    bld temp, 0
    eor result, temp

    bst input, 3            ; Xor "Input" bit 3 with subresult
    bld temp, 0
    eor result, temp

    lsl input               ; Update new value in shift register
    com result
    bst result, 0
    bld input, 0

    pop temp                ; Restore values from Stack end return
    pop result
    ret

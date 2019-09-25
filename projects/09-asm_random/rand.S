;*
;* ---------------------------------------------------------------------
;* Author:      Tomas Fryza, Wykys
;*              Dept. of Radio Electronics, Brno Univ. of Technology
;* Created:     2017-11-09
;* Last update: 2019-07-16
;* Platform:    ATmega328P, AVR 8-bit Toolchain 3.6.2
;* ---------------------------------------------------------------------
;* Description: Implementation of 8- and 16-bit LFSR-based (Linear
;* Feedback Shift Register) pseudo-random generators.
;* TODO: Verify functionality of 8-bit pseudo-random generator and
;* complete 16-bit generator.
;*

; Set offset for control register addresses (NEEDED FOR I/O REGISTERS)
#define __SFR_OFFSET 0
#include <avr/io.h>

#define result  r16
#define temp    r17
#define input   r24

;**
; * Brief:  LFSR-based 8-bit pseudo-random generator.
; * Input:  r24 - Current value of 8-bit shift register
; * Return: r24 - Updated value of 8-bit shift register
; * Note:   LFSR taps positions are: 7, 5, 4, 3
; * https://www.xilinx.com/support/documentation/application_notes/xapp052.pdf
; * http://courses.cse.tamu.edu/walker/csce680/lfsr_table.pdf
; *
.global rand8_asm
rand8_asm:
    push result         ; Save result on the Stack
    push temp           ; Save temp on the Stack

    ; Copy input bit 7
    bst input, 7        ; Store bit 7 of input in T Flag
    bld result, 0       ; Load T Flag into bit 0 of result
    ; Copy input bit 5
    bst input, 5        ; Store bit 5 of input in T Flag
    bld temp, 0         ; Load T Flag into bit 0 of temp
    ; Xor input bits 7 and 5
    eor result, temp

    ; Copy input bit 4 and xor with previous result
    bst input, 4        ; Store bit 4 of input in T Flag
    bld temp, 0         ; Load T Flag into bit 0 of temp
    eor result, temp

    ; Copy input bit 3 and xor with previous result
    bst input, 3        ; Store bit 3 of input in T Flag
    bld temp, 0         ; Load T Flag into bit 0 of temp
    eor result, temp

    ; Invert result
    com result
    ; Shift all input bits to left
    lsl input
    ; Copy result as a new bit at LSB position
    bst result, 0       ; Store bit 0 of result in T Flag
    bld input, 0        ; Load T Flag into bit 0 of input

    pop temp            ; Restore temp from Stack
    pop result          ; Restore result from Stack
    ret                 ; Return from subroutine

;**
; * Brief:  LFSR-based 16-bit pseudo-random generator.
; * Input:  r25:r24 - Current value of 16-bit shift register
; * Return: r25:r24 - Updated value of 16-bit shift register
; * Note:   LFSR taps positions are: WRITE YOUR CODE HERE
; *
.global rand16_asm
rand16_asm:
    push result         ; Save result on the Stack
    push temp           ; Save temp on the Stack

    ; WRITE YOUR CODE HERE

    pop temp            ; Restore temp from Stack
    pop result          ; Restore result from Stack
    ret                 ; Return from subroutine

;*
;* ---------------------------------------------------------------------
;* Author:      Tomas Fryza, Wykys
;*              Dept. of Radio Electronics, Brno Univ. of Technology
;* Created:     2017-11-09
;* Last update: 2019-11-15
;* Platform:    ATmega328P, AVR 8-bit Toolchain 3.6.2
;* ---------------------------------------------------------------------
;* Description:
;*    Implementation of 4-, 8- and 16-bit LFSR-based (Linear Feedback 
;*    Shift Register) pseudo-random generators.
;*

; Set offset for control register addresses (NEEDED FOR I/O REGISTERS)
#define __SFR_OFFSET 0
#include <avr/io.h>

#define result  r16
#define temp    r17
#define input   r24

;**
; * Brief:  LFSR-based 4-bit pseudo-random generator.
; * Input:  r24 - Last value of shift register
; * Return: r24 - New value of shift register
; * Note:   LFSR taps positions are: 3, 2
; *
.global rand4_asm
rand4_asm:
    push result         ; Save Result on the Stack
    push temp           ; Save Temp on the Stack

    bst input, 3        ; Copy Input bit 3 to T Flag...
    bld result, 0       ; ...and then to Result bit 0
    bst input, 2        ; Copy Input bit 2 to T Flag
    bld temp, 0         ; ...and then to Temp bit 0
    eor result, temp    ; Xor Input bits 3 and 2

    com result          ; Invert Result
    lsl input           ; Shift all Input bits to left
    andi input, 0b11101111  ; Make sure bit 4 is cleared
    bst result, 0       ; Copy Result bit 0 to T Flag...
    bld input, 0        ; ...and then to Input bit 0

    pop temp            ; Restore temp from Stack
    pop result          ; Restore result from Stack
    ret                 ; Return from subroutine

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
    push result         ; Save Result on the Stack
    push temp           ; Save Temp on the Stack

    bst input, 7        ; Copy Input bit 7 to T Flag...
    bld result, 0       ; ...and then to Result bit 0
    bst input, 5        ; Copy Input bit 5 to T Flag
    bld temp, 0         ; ...and then to Temp bit 0
    eor result, temp    ; Xor Input bits 7 and 5

    bst input, 4        ; Copy Input bit 4 to T Flag
    bld temp, 0         ; ...and then to Temp bit 0
    eor result, temp    ; Xor Input bit 4 and previous result

    bst input, 3        ; Copy Input bit 3 to T Flag
    bld temp, 0         ; ...and then to Temp bit 0
    eor result, temp    ; Xor Input bit 3 and previous result

    com result          ; Invert Result
    lsl input           ; Shift all Input bits to left
    bst result, 0       ; Copy Result bit 0 to T Flag...
    bld input, 0        ; ...and then to Input bit 0

    pop temp            ; Restore Temp from Stack
    pop result          ; Restore Result from Stack
    ret                 ; Return from subroutine

;**
; * Brief:  LFSR-based 16-bit pseudo-random generator.
; * Input:  r25:r24 - Current value of 16-bit shift register
; * Return: r25:r24 - Updated value of 16-bit shift register
; * Note:   LFSR taps positions are: 15, 14, 12, 3
; *
.global rand16_asm
rand16_asm:
    push result         ; Save Result on the Stack
    push temp           ; Save Temp on the Stack

    ; TODO: Program 16-LFSR counter

    pop temp            ; Restore Temp from Stack
    pop result          ; Restore Result from Stack
    ret                 ; Return from subroutine

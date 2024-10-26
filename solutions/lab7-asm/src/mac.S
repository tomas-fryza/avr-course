;* ---------------------------------------------------------------------
;*
;* 8-bit unsigned Multiply-and-Accumulate in assembly.
;* (c) 2022-2024 Tomas Fryza, MIT license
;*
;* Developed using PlatformIO and AVR 8-bit Toolchain 3.6.2.
;* Tested on Arduino Uno board and ATmega328P, 16 MHz.
;*
;* ---------------------------------------------------------------------

;* Includes ------------------------------------------------------------
; Set offset for control register addresses (NEEDED FOR I/O REGISTERS)
#define __SFR_OFFSET 0
#include <avr/io.h>


;* Defines -------------------------------------------------------------
#define in_out_reg r24
#define a          r22
#define b          r20


;* Function definitions ------------------------------------------------
;**********************************************************************
;* Function: multiply_accumulate_asm
;* Purpose:  Multiply-and-Accumulate operation: in_out_reg = in_out_reg + (a*b).
;* Input(s): r24 - Current MAC value
;*           r22 - Value A
;*           r20 - Value B
;* Return:   r24 - New MAC value
;**********************************************************************/
.global multiply_accumulate_asm
multiply_accumulate_asm:
    mul a, b            ; Multiply Unsigned, r1:0 = a * b
    add in_out_reg, r0  ; Accumulate just low product result
    ret                 ; Return from subroutine

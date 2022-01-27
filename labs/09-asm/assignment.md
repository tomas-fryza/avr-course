# Lab 9: YOUR_FIRSTNAME LASTNAME

Link to this file in your GitHub repository:

[https://github.com/your-github-account/repository-name/lab_name](https://github.com/...)

### Instruction set

1. Complete table with selected instructions:

   | **Instruction** | **Operation** | **Description** | **Cycles** |
   | :-- | :-: | :-- | :-: |
   | `add Rd, Rr` | Rd = Rd + Rr | Adds two registers without Carry flag | 1 |
   | `andi Rd, K` | Rd = Rd and K | Logical AND between register Rd and 8-bit constant K | 1 |
   | `bld Rd, b` |  |  |  |
   | `brne k` |  |  |  |
   | `bst Rd, b` |  |  |  |
   | `eor Rd, Re` |  |  |  |
   | `ldi Rd, K` |  |  |  |
   | `mov Rd, Rr` |  |  |  |
   | `out A, Rr` |  |  |  |
   | `push Rr` |  |  |  |
   | `rcall k` |  |  |  |
   | `rjmp k` |  |  |  |
   | `rol Rd` |  |  |  |
   | `ror Rd` |  |  |  |
   | `sbi A, b` |  |  |  |
   | `nop` |  |  |  |

### 4-bit LFSR

1. Code listing of C function for 4-bit LFSR generator. Always use syntax highlighting and meaningful comments:

```c
uint8_t rand4_c(uint8_t value)
{
    // WRITE YOUR CODE HERE

}
```

### Sum of the products (SoP)

1. Code listing of assembly function to calculate the sum of the products. Always use syntax highlighting and meaningful comments:

```nasm
;**********************************************************************
;* Function: sop_asm
;* Purpose:  Sum of the product of two integer vectors with the same length.
;* Note:     Consider 8-bit values/operations only.
;* Input:    r24 - Vector a
;* Input:    r22 - Vector b
;* Input:    r20 - Number of vector elements
;* Return:   r24 - Sum of the product value
;**********************************************************************/
.global sop_asm
sop_asm:
    ; WRITE YOUR CODE HERE

    ret                     ; Return from subroutine
```

### Sorting function

1. Flowchart figure for function `uint8_t* sort_values(uint8_t* data, uint8_t length=3)` which sorts three integer values from input array in descending order. The image can be drawn on a computer or by hand. Use clear descriptions of the individual steps of the algorithms.

   ![your figure]()

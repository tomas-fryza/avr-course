# Lab 2: Programming in C

* [Pre-Lab preparation](#preparation)
* [Part 1: Hello world](#part1)
* [Part 2: Variables and operators](#part2)
* [Part 3: Progress bar](#part3)
* [Challenges](#challenges)
* [References](#references)

### Learning objectives

* Understand the basic structure of C code
* Use C code control structures: loops, conditions
* Understand the binary operators

<a name="preparation"></a>

## Pre-Lab preparation

1. Fill in the following table and enter the number of bits and numeric range for the selected data types defined by C.

   | **Data type** | **Number of bits** | **Range** | **Description** |
   | :-: | :-: | :-: | :-- |
   | `uint8_t`  | 8 | 0, 1, ..., 255 | Unsigned 8-bit integer |
   | `int8_t`   |  |  |  |
   | `uint16_t` |  |  |  |
   | `int16_t`  |  |  |  |
   | `float`    |  | -3.4e+38, ..., 3.4e+38 | Single-precision floating-point |
   | `void`     | -- | -- | Depending on the context, it means *no type*, *no value* or *no parameters* |

<a name="part1"></a>

## Part 1: Hello world

1. Use one of the online C editors/ compilers and test the first C code:
   * [Online C Compiler](https://www.onlinegdb.com/online_c_compiler)
   * [Programiz C Online Compiler](https://www.programiz.com/c-programming/online-compiler/)
   * [OneCompiler](https://onecompiler.com/c)
   * ...

2. Use `printf` function and test the escape sequences:
   * **Newline** (`\n`): Creates a new line, moving the cursor to the beginning of the next line.

   * **Carriage Return** (`\r`): Moves the cursor to the beginning of the current line. Useful for overwriting text on the same line.

   * **Tab** (`\t`): Inserts a horizontal tab, which typically advances the cursor to the next tab stop. Tab stops are usually set at regular intervals, such as every 4 or 8 spaces.

   * **Backspace** (`\b`): Moves the cursor one position to the left. Useful for removing characters.

   * **Escape** (`\x1b`): Starts an escape sequence that can be used to control text formatting, colors, and other terminal features. For example, you can change text color using ANSI escape codes.






<a name="part2"></a>

## Part 2: Variables and operators

1. Use Standard C integer library and find out the data types ranges.

   ```c
   #include <stdio.h>    // Standard C input/output library
   #include <stdint.h>   // Standard C integer library

   int main(void)        // Main function with no input parameters
   {                     // Beginning of function body
       int8_t  a = 200;  // Definition of two local variables
       uint8_t b = 200;
                         // Print formated string to a Terminal
       printf("Print int8 value: %d\n", a);  // Integer `a` will be printed to `%d`
       printf("Print uint8 value: %d\n", b); // Formatting char. `\n` inserts new line
       printf("Size of int32_t: %d B\n", sizeof(int32_t));

       return 0;         // Return value of main function
   }                     // End of function body
   ```

2. Program the function to display an arrow of symbols. Note that you can use `if` statements and `for` loops.

   ```shell
   *
   **
   ***
   ****
   *****
   ****
   ***
   **
   *
   ```

3. To control individual bit(s) within a variable, the following binary operations are used.
   1. `|` OR
   2. `&` AND
   3. `^` XOR
   4. `~` NOT
   5. `<<` binary shift to left

   | **b** | **a** |**b OR a** | **b AND a** | **b XOR a** | **NOT b** |
   | :-: | :-: | :-: | :-: | :-: | :-: |
   | 0 | 0 | 0 | 0 | 0 | 1 |
   | 0 | 1 | 1 | 0 | 1 | 1 |
   | 1 | 0 | 1 | 0 | 1 | 0 |
   | 1 | 1 | 1 | 1 | 0 | 0 |

   ```c
   // Set bit value to 1
   reg = reg & (1<<bit);

   // Clear bit value to 0
   reg = reg & ~(1<<bit);

   // Toggle bit value
   reg = reg ^ (1<<bit);
   ```

   ![binary operations](images/binary_operations.png)

<a name="challenges"></a>

## Challenges

1. TBD

<a name="references"></a>

## References

1. Parewa Labs Pvt. Ltd. [C User-defined functions](https://www.programiz.com/c-programming/c-user-defined-functions)

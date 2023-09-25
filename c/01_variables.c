#include <stdio.h>    // Standard C input/output library
#include <stdint.h>   // Standard C integer library

int main(void)        // Main function with no input parameters
{                     // Beginning of function body
    int8_t  a = 200;  // Definition of two local variables
    uint8_t b = 200;
                      // Print formated string to a Terminal
    printf("Print int8 value: %d\n", a);  // Integer `a` will be printed to `%d`
    printf("Print uint8 value: %d\n", b); // Formatting char. `\n` inserts new line
    printf("Size of uint8: %d B\n", sizeof(uint8_t));

    return 0;         // Return value of main function
}                     // End of function body

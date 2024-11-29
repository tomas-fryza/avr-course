#include <stdio.h>
#include "compute.h"

int main(void)
{
    float a = 10.25;
    float result;

    printf("a: \t%7.2f\n", a);

    result = square(a);
    printf("square: %7.3f\n", result);

    result = square_root(a);
    printf("sqrt: \t%7.2f\n", result);
	
    return 0;
}

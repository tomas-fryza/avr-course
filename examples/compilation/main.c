#include <stdio.h>
#include "utils.h"

#define N 30

int main()
{
    int result = square(N);
    printf("square: \%d\n", result);

    for (int i = 0; i < N; i++) {
        result = add(i*N, 50);
        printf("addition: \%d\n", result);
    }

    return 0;
}

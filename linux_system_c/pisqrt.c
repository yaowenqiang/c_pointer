/*
 * pointer.c - Calculate the square of PI 100.000.000 times
 *
 */
#include <stdio.h>
#include <math.h>

int main(void)
{
    double pi = M_PI; /* Defined in <math.h> */
    double pisqrt;
    long i;

    for (i = 0; i < 100000000; ++i) {
        pisqrt = sqrt(pi);
    }
    return 0;
}

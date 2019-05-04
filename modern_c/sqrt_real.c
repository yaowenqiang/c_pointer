/*
 * sqrt_equal.c 
 */

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

#ifdef __STDC__NO_COMPLEX__
# error "we need complex arithmetic"
#endif

double complex sqrt_real(double x );

int main(void)
{
    double complex y, z;
    y = sqrt_real(1.0);
    z = sqrt_real(-1.0);
    printf("%.1f+%.1fi\n", creal(y), cimag(y));
    printf("%.1f+%.1fi\n", creal(z), cimag(z));
    return 0;
}
double complex sqrt_real(double x )
{
    return (x < 0 )? CMPLX(0, sqrt(-x)) : CMPLX(sqrt(x), 0);
}

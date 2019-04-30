/*
 * tgmath stands for type generic mathematical functions
 */


#include <stdio.h>
#include <stdio.h>
#include <tgmath.h>

int main(void)
{
    double const eps = 1E-9;
    double x = 0.5;
    printf("%e\n",fabs(x));
    double a = 3.14;
    while (fabs(1.0 - a*x) >= eps) {
      x *= (2.0 - a*x);
      printf("%e\n",fabs(1.0 - a*x));
      printf("%e\n",x);
    }
    return 0;
}

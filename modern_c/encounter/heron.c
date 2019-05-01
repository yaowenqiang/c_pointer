/*
 * heron.c
 */

#include <stdio.h>
#include <stdlib.h>

/* lower and upper iteration limits centered around 1.0 */
static double const eps1m01 = 1.0 - 0x1P - 01;
static double const eps1p01 = 1.0 + 0x1P - 01;
static double const eps1m24 = 1.0 - 0x1P - 24;
static double const eps1p24 = 1.0 + 0x1P - 24;

int int main(int argc, char* argv[argc+1])
{
    for (int i = 0; i < argc; ++i) {
       double const a = strtod(argv[i], 0); 
       double x = 1.0;
       for(;;) {
           double prod = a * x;
           if (prod < epsm01) {
               x *= 2.0;
           } else if (eps1p01 )
       }
              
    } 
    
    return 0;
}

/*
 * bounds_for_scalar_types.c
 */

#include <stdio.h>
#include <stdio.h>

// size_t SIZE_MAX
#include <stdint.h>

//double DBL_MIN, DBL_MAX
#include <float.h>

//signed  unsigned  INT MIN ,INT MAX
#include <limits.h>

#include <stdbool.h>


#include <stddef.h>

int main(void)
{

    
    //stdint.h
    size_t a = SIZE_MAX; // [0, 2³² -1] or [0, 2⁶⁴-1]
    //float.h
    double b = DBL_MIN;  // [±2⁻¹⁰²⁴⁻², ±2¹⁰²⁴]
    double c = DBL_MAX;
    //limits.h
    signed int d = INT_MIN;// [-2⁻³¹, 2⁻³¹ -1]
    signed int e = INT_MAX;
    unsigned int f = UINT_MAX;// [0, 2³² -1]

    bool g = false;
    bool h = true;// stdbool.h

    //stdint.h
    //limits.h
    ptrdiff_t i = PTRDIFF_MIN;
    ptrdiff_t j = PTRDIFF_MAX;

    char k = CHAR_MIN;
    char l = CHAR_MAX;

    unsigned char m = UCHAR_MAX; //[0, UCHAR_MAX]


    printf("%zu\n",a);
    printf("%f\n", b);
    printf("%f\n", c);
    printf("%d\n", d);
    printf("%d\n", e);
    printf("%d\n", f);
    printf("%d\n", g);
    printf("%d\n", h);

    printf("%td\n", i);
    printf("%td\n", j);

    printf("%d\n", k);
    printf("%d\n", l);
    printf("%s\n", m);
    return 0;
}

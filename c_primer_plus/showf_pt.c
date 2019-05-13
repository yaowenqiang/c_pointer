/*
 * showf_pt.c - 以两种方式显示浮点值
 */

#include <stdio.h>
int main(void)
{
    float about = 32000.0;
    double abet = 2.14e9;
    long double dip = 5.32e-5;
    printf("%f can be written %e\n", about, about);
    printf("%f can be written %e\n", abet, abet);
    //printf("%f can be written %e\n", dip, dip);
    printf("%Lf can be written %Le\n", dip, dip);

    return 0;
}

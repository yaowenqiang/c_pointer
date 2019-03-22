/*
 * binary_to_decimal.c - convert the given binary number todecimal
 */
#include <stdio.h>
int main(void)
{
    int num, binary_val, decimal_val = 0, base = 1, rem;
    printf("Enter a binary number(1s and 0s) \n");
    scanf("%d", &num); /* maxinum five digits */

    binary_val = num;
    while (num > 0) {
       rem = num % 10;
       decimal_val = decimal_val + rem * base;
       num = num / 10;
       base = base *2;
    }
    printf("The Binary number is %d", binary_val);
    printf("The decimal_val is %d", decimal_val);
}

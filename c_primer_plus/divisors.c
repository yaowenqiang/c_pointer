/*
 * divisors.c - 使用嵌套if 显示一个数的约数 
 */

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    unsigned long num;
    unsigned long div;
    bool isPrime;
    printf("Please enter an integer for analysis: \n");
    while(scanf("%lu", &num) == 1) {
        for (div = 2, isPrime = true; (div * div) <= num; div++) {
           if (num % div == 0 ) {
               if ((div * div) != num) {
                   printf("%lu is divisible by %lu and %lu\n",num, div, num / div);
               } else {
                   printf("%lu is divisible by %lu\n",num, div);
               }
               isPrime = false;
           } else {
           } 
        }

        if (isPrime) {
           printf("%lu is prime.\n", num); 
        }

        printf("Please enter another integer for analysis: \n");
        printf("Enter q to quite.\n");
    }
    printf("Bye.\n");
    return 0;
}

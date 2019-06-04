/*
 * addmup.c - 四种类型的语句 
 */

#include <stdio.h>
int main(void)
{
    int count, sum;
    int n = 0;
    int y;
    y = n++ + ++n;
    count = 0;
    sum = 0;
    while (count++ < 20) {
        sum = sum + count;
    }
    printf("sum = %d\n", sum);
    printf("%d\n",y);
    return 0;
}

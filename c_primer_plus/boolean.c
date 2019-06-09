/*
 * boolean.c - 使用 _Bool类型的变量
 */

#include <stdio.h>
int main(void)
{
    long num;
    long sum = 0L;
    _Bool input_is_good;
    printf("Please enter an inter to be summed.\n");
    printf("(q to quitwge:\n");
    input_is_good  = (scanf("%ld", &num) == 1);
    while (input_is_good) {
        sum = sum + num;
        printf("Please enter an inter to be summed(q to quit).\n");
        input_is_good  = (scanf("%ld", &num) == 1);
    }
    printf("Those integers sum to %ld.\n", sum);
    return 0;
}

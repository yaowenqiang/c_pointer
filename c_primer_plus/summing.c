/*
 * summing.c - 
 */

#include <stdio.h>
int main(void)
{
    long num;
    //long sum = 0L;
    long sum = 0;
    int status;
    printf("Please enter an integer bo te summed\n");
    printf("q to quit): \n");
    status = scanf("%ld", &num);
    while (status == 1) {
        sum = sum + num;
        printf("Please enter next integer (q to quit)");
        status = scanf("%ld", &num);
    }
    printf("Those integers sum to %ld.\n", sum);
    return 0;
}

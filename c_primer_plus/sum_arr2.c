/*
 * sum_arr2.c - 数组元素之各
 */

#include <stdio.h>
#define SIZE 10
int sump(int * start ,int * end);
int main(void)
{
    long answer;
    int marbles[SIZE] = {1,2,3,4,5,6,7,8,9,10};    
    answer = sump(marbles, marbles + SIZE);
    printf("The total number of marbles is %ld\n", answer);
    return 0;
}


int sump(int * start , int * end)
{
    int total = 0;
    while (start < end) {
        total += *start;
        start ++;
    }
    return total;

}

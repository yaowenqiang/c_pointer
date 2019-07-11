/*
 * sum_arr1.c - 数组元素之各
 */

#include <stdio.h>
#define SIZE 10
int sum(int arr[], int n);

int main(void)
{
    int marbles[SIZE] = {1,2,3,4,5,6,7,8,9,10};    
    long answer;
    answer = sum(marbles, SIZE);
    printf("The total number of marbles is %ld\n", answer);
    printf("The size of marbles is %zd bytes\n", sizeof marbles);
    return 0;
}

int sum(int arr[], int n)
{
    int i;
    int total = 0;
    for (i = 0; i < n; i++) {
       total += arr[i]; 
    }
    printf("The size of arr is %zd bytes\n", sizeof arr);
    return total;
}

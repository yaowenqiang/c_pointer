/*
 * 使用memcpy() 和 memmove()
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10

void show_array(const int ar[], int n);
_Static_assert(sizeof(double) == 2 * sizeof(int), "double not twice int size");

int main(void)
{
    int values[SIZE] = {1,2,3,4,5,6,7,8,9,10};
    int target[SIZE];
    double curious[SIZE/2] = {2.0, 2.0e5, 2.0e10, 2.0e20, 5.0e30 };

    puts("memcpy() used:");
    puts("values (original data): ");
    show_array(values, SIZE);

    puts("\nUtarget(copy of values): ");
    memcpy(target, values, SIZE * sizeof(int));
    show_array(target, SIZE);

    puts("\nUsing memcpy() with overlapping ranges: ");
    memcpy(values + 2, values, 5 * sizeof(int));
    show_array(target, SIZE);



    puts("values -- elements 0-4 copied to 2-6: ");
    show_array(values, SIZE);

    puts("\nusing memcpy() to copy double to int: ");
    memcpy(target, curious, (SIZE / 2) * sizeof(double));
    puts("target -- 5 doubles into 10 int position: ");
    show_array(target, SIZE / 2 );
    show_array(target + 5, SIZE / 2);

    return 0;
}


void show_array(const int ar[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", ar[i]);
    }
    putchar('\n');
}



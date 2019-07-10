/*
 * one_or_zero.c  find  how many elements in a array that is greater then zero
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double largeA[100] = {0};
    size_t sign[2] = {0, 0};
    size_t isset[2] = {0, 0};
    for (size_t i = 0; i < 100; ++i) {
        largeA[i] = i > 20;
    }
    for (size_t i = 0; i < 100; ++i) {
        sign[(largeA[i] < 1.0)] += 1;
    }

    printf("count 0 = %zu, count 1 = %zu\n", sign[0], sign[1]);

    for (size_t i = 0; i < 100; i++) {
        isset[!!largeA[i]] += 1;
    }

    printf("count 0 = %zu, count 1 = %zu\n", isset[0], isset[1]);

    return 0;
}

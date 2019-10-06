#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main(void)
{
    int ct1 = clock() / CLOCKS_PER_SEC;
    sleep(10);
    int ct2 = clock() / CLOCKS_PER_SEC;
    printf("%d\n", ct2 - ct1);
    return 0;
}

#include <stdio.h>
#include <string.h>

int main(void)
{
    //int foo[5] = {0,0,0, 0, 0}, n=0;
    int foo[] = {0};
    int n = 0;
    //memset((char *) 0x0, 1, 100);
    //memset(foo, 1, 100);
    memset(foo, 1, sizeof(foo)/sizeof(int));
    printf("Initial value of n is %d \n", n);
    printf("len of foo is %ld \n", sizeof(foo));
    return 0;
}

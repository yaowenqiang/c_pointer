/*
 * r_drive0.c -- 测试 rand0()  函数 
 * 与rand0.c 一起编译
 */

#include <stdio.h>
extern unsigned int rand0(void);
extern int rand1(void);
extern void srand1(unsigned int x);
int main(void)
{
    int count;
    unsigned seed;
    /*
    for (count = 0; count < 5; count++) {
        printf("%d\n", rand0());
    }
    */

    printf("Please enter your choice for seed.\n");
    while (scanf("%u", &seed) == 1) {
        srand1(seed);
        for (count = 0; count < 5; count++) {
            printf("%d\n", rand1());
        }
        printf("Please enter your choice for seed.\n");

    }
    printf("Done\n");
    return 0;
}

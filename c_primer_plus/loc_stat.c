/*
 * loc_stat.c - 使用发问静态变量
 */

#include <stdio.h>
void trystat(void);
int main(void)
{
    int count;
    for (count = 0; count < 3; count++) {
        printf("Here comes iteration %d:\n", count);
        trystat();
    }
    return 0;
}

void trystat()
{
    int fade = 1;
    static int stat = 1;
    printf("fade = %d and stay = %d\n", fade++, stat++);
}


/*
 * 神秘函数，参数是一个0 - 100的值
 */

#include <stdio.h>
#include <stdlib.h>
void mystery(int n);
int main(void)
{
    mystery(1);
    return 0;
}

void mystery(int n)
{
    n += 5;
    n /= 10;
    printf("%s\n", "****************", +10 - n);
}

/*
 * put2.c - 打印一个字符串， 并统计打印的字符数
 */

#include <stdio.h>
int put2(const char * string)
{
    int count = 0;
    while(*string)
    {
        putchar(*string++);
        count ++;
    }
    putchar('\n');
    return count;
}
int main(void)
{
    const char * p = "i am a string";
    int count;
    count  = put2(p);
    printf("%d\n", count);
    return 0;
}

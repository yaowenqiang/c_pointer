/*
 * strings.c -  字符串的格式化
 */

#include <stdio.h>
#define BLURB "Authentic initation!!"

int main(void)
{
    printf("%s\n", BLURB);
    printf("/%2/s\n", BLURB);
    printf("%24s\n", BLURB);
    printf("%24.5s\n", BLURB);
    printf("%-24.5s\n", BLURB);
    return 0;
}

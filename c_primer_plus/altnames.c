/*
 * altnames.c - 可移植的整数类型别名
 */
#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    int16_t mel6;
    mel6 = 4593;
    printf("First, assume int16_t is short:\n");
    printf("mel6 = %hd\n", mel6);
    printf("Next, let's not maky any assumptions.\n");
    printf("Instead, use  a \"macro\" from inttypes.\n");
    printf("mel6 = %" PRId16 "\n", mel6);
    return 0;
}

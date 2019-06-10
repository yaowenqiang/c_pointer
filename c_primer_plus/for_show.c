/*
 * for_show.c
 */
#include <stdio.h>
int main(void)
{
    int num = 1;
    for(printf("Keep entering numbers!");num !=6;) {
        scanf("%d", &num);
    }
    printf("That's the one i want!\n");
    return 0;
}

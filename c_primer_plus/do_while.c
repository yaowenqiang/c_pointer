/*
 * do_while.c -退出条件循环
 */
#include <stdio.h>
int main(void)
{
    const int secrect_code = 13;
    int code_entered;
    do {
        printf("To enter the triskaidekaphobia therapy club.\n");
        printf("Please enter the secrect code number:\n");
        scanf("%d", &code_entered);
    } while (code_entered != secrect_code);
    printf("Congratulations! YOu are cured!\n");
    return 0;
}

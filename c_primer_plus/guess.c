/*
 * guess.c - 一个低效且错误的猜数程序
 */

#include <stdio.h>
int main(void)
{
    int guess = 1;
    char response;
    printf("Pick an interger from 1 to 100, I will try to guess ");
    printf("it.\nRespond with a y if my guess is right and with ");
    printf("\nan n if it is wrong.\n") ;
    printf("Uh... is your number %d?\n", guess);
    while ((response = getchar()) != 'y') {
        printf("Well, then ,is it %d?\n", ++guess);
        if (response == 'n') {
            printf("Well, then, is it %d\n", ++guess);
        } else {
            printf("Sorry, I understand only y or n.\n");
        }
        while(getchar() != '\n') {
            continue;
        }
    }
    printf("I knew I could do it!\n");
    return 0;
}

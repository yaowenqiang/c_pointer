/*
 * input.c - 什么情况下使用&
 */

#include <stdio.h>

int main(void)
{
    int age;
    float assets;
    char pet[30];
    char job[30];
    char address[30];
    

    printf("Enter your age, assets, and favorite pet.\n");
    scanf("%d %f", &age, &assets);
    scanf("%s", pet);
    printf("%d $%.2f %s\n", age, assets, pet);
    printf("Enter your job, address.\n");
    scanf("%s", job);
    scanf(" %s", address);
    printf("YOU job is %s and your address is %s\n", job, address);
    return 0;
}


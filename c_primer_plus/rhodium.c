/*
 * rhodium.c - 用金属铑衡量您的体重
 */

#include <stdio.h>
int main(void)
{
    float weight;   /* 用户的体重 */
    float value;    /* 相等重量的铑的价值 */
    printf("Are you worth your weight in rhodium?\n");
    printf("Let's check it out\n");
    printf("Please enter your weight in pounds:\n");
    scanf("%f", &weight);
    /* 假设佬为每盎司770美元 */
    /* 14.5833把党重制的英镑转换为金属制的盎司 */
    value = 770 * weight * 14.5833;
    printf("Your weight in rhodium is worth $%.2f.\n", value);
    printf("You are easily worth that! If rhodum prices drop.\n");
    printf("eat more to maintain you value.\n") ;

    return 0;
}

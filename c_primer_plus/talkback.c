/*
 * talkback.c - 一个能为您提供一些信息的对话程序
 */


#include <stdio.h> 
#include <string.h>//提供strlen()函数的原型 )

#define DENSITY 62.4 //人的密度(单位是 英镑/每立方尺)

int main(void)
{
    float weight, volume;
    int size, letters;
    char name[40]; //name是一个有40个字符的数组

    printf("HI! What's your first name in pounds?'\n");
    scanf("%s", name);
    printf("HI! What's your weight in pounds?'\n");
    scanf("%f", &weight);
    printf("%s, what's your weight in pounds?\n", name);
    scanf("%f", &weight);

    size = sizeof name;

    letters = strlen(name);
    volume = weight / DENSITY;

    printf("Well! %s, your volumne is %2.2f cubic feet. '\n", name, volume);
    printf("Also!, your first name has %d letters. '\n", letters);
    printf("and we have %d bytes to store it in.\n", size);

    return 0;


}
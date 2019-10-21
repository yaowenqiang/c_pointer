#include <stdio.h>
int main(void)
{
    //char a = '';
    char a = '\0';
    printf("%c\n", a);
    printf("Enter a character: ");
    scanf("%c", &a);
    printf("%c\n", a);
    printf("%d\n", a);

    return 0;
}

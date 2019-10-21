#include <stdio.h>
int main(void)
{
    //char a = '';
    char a = '\0';
    printf("%d\n", a);
    char b[] = "a";
    printf("%c\n", a);
    printf("Enter a character: ");
    //scanf("%c", &a);
    a = 'a';
    printf("%c\n", a);
    printf("%d\n", a);
    printf("b is %s\n", b);
    printf("before: b[0] is %c\n", b[0]);
    b[0] = '\0';
    printf("after: b[0] is %c\n", b[0]);
    printf("%s\n", b);
    char c[] = "";
    printf("c is %s\n", c);
    printf("c[0] is %c\n", c[0]);
    printf("c[0] is %d\n", c[0]);

    printf("c[1] is %c\n", c[1]);
    printf("c[1] is %d\n", c[1]);

    printf("c[2] is %c\n", c[2]);
    printf("c[2] is %d\n", c[2]);

    return 0;
}

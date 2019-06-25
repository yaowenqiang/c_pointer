/*
 * showchar1.c - 带有一个较大的I/O问题的程序
 */

#include <stdio.h>
void display(char cr, int lines, int width);

int main(void)
{
    int ch;
    int rows, cols;
    printf("Enter a character and two integers\n");
    while ((ch = getchar()) != '\n') {
        //printf("%c\n", ch);
        scanf("%d %d", &rows, &cols);
        //printf("%d %d", rows, cols);
        display(ch, rows, cols);
        printf("Enter another character and two integers\n");
        printf("Enter a newline to quite.\n");
    }
    printf("Bye\n");
    return 0;
}

void display(char cr, int lines ,int width)
{
    int row, col;
    for ( row = 1; row <=lines; row++) {
        for (col = 1; col <= width; col++) {
            putchar(cr);
        }
        putchar('\n');
    }
}

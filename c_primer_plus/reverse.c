/*
 * reverse.c - 倒序显示文件的内容
 */

#include <stdio.h>
#include <stdlib.h>
#define CNTL_Z '\032' /* DOS 文本文件中的文件结尾标记*/ 
#define SIZE 81



int main(void)
{
    FILE *fp;
    char file[SIZE];
    char ch;
    long count, last;

    puts("Enter the name of the file to be processed:");
    scanf("%80s", file);

    if ((fp = fopen(file, "rb")) == NULL) {
        fprintf(stderr, "can't open %s\n", file);
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0L, SEEK_END);
    last = ftell(fp);

    for (count = 1L; count <= last; count++) {
        fseek(fp, -count, SEEK_END);
        ch = getc(fp);
        if (ch != CNTL_Z && ch !=  '\r') {
            putchar(ch);
        }
    }
    putchar('\n');

    fclose(fp);

    return 0;
}

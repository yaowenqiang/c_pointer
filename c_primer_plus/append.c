/*
 * append.c - 把文件附加到另一个文件末尾
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 4096
#define SLEN 81
void append(FILE *source, FILE *dest);

char * s_gets(char *st, int n);

int main(void)
{
    FILE *fa, *fs;
    int files = 0;
    char file_app[SLEN];
    char file_src[SLEN];
    int ch;
    int err;
    puts("Enter name of destination file:");
    s_gets(file_app, SLEN);

    if ((fa = fopen(file_app, "a+")) == NULL) {
        fprintf(stderr, "Can't open %s\n", file_app);
        err = ferror(fa);
        printf("%d",err);
        exit(EXIT_FAILURE);
    }

    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0) {
        fputs("Can't create input buffer\n", stderr);
        exit(EXIT_FAILURE);
    }

    puts("Enter name of first source file (empty line to quit):");
    while (s_gets(file_src,SLEN) && file_src[0] != '\0') {
        if (strcmp(file_src, file_app) == 0) {
            fputs("Can't append file to itself\n", stderr);
        } else if ((fs = fopen(file_src, "rb")) == NULL) {
            fprintf(stderr, "Can't open %s\n", file_src);
            err = ferror(fs);
            printf("%d",err);
        } else {
            if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0) {
                fputs("Can't create input buffer\n", stderr);
            }
            append(fs, fa);

            if(ferror(fs) != 0) {
                fprintf(stderr, "Error in reading file %s\n", file_src);
            }
            if (ferror(fa) != 0) {
                fprintf(stderr, "Error in writing file %s\n", file_app);
            }
            fclose(fs);
            files++;
            printf("File %s appended.\n", file_src);
            puts("Next file (empty line to quit):");
        }
    }

    printf("done appendeding.%d files appended\n", files);
    rewind(fa);

    printf("%s contents\n", file_app);
    while ((ch = getc(fa)) != EOF) {
        putchar(ch);
    }
    puts("Done displaying.");
    fclose(fa);

    return 0;
}

void append(FILE *source, FILE *dest)
{
    //printf("%p\n", source);
    //printf("%p\n", dest);
    size_t bytes;
    static char temp[BUFSIZE];
    //bytes = fread(temp, sizeof(char), BUFSIZE, source);
    bytes = fread(temp, 1, 1, source);
    if(ferror(source) != 0) {
        fprintf(stderr, "Error in reading file \n");
    }
    printf("%zu\n", bytes);
    printf("%s\n", temp);
    while ((bytes = fread(temp, BUFSIZE,sizeof(char), source))> 0) {
        printf("%s\n", temp);
        fwrite(temp, sizeof(char), bytes, dest);
    }
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n , stdin);

    if(ret_val) {
        find = strchr(st, '\n');
        if (find) {
            *find = '\n';
        } else {
            while (getchar() != '\n') {
                continue;
            }
        }
    }
    return ret_val;
}

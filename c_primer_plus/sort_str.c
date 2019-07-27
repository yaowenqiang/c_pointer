/*
 * sort_str.c - 诗篇字符串，并排序字符串
 */

#include <stdio.h>
#include <string.h>
#define SIZE 81
#define LIM 20
#define HALT ""

void str_sort(char * strings[], int num);
char * s_gets(char * str, int n);
int main(void)
{
    char input[LIM][SIZE]; /* 保存输入的数组 */
    char *ptstr[LIM]; /* 内含指针变量的数组 */
    int ct = 0; /* 输入计数 */
    int k;/* 输出计数 */
    printf("Input up to %d lines, and I will sort them.\n", LIM);
    printf("To stop, press the Enter key at a line's start\n");
    while (ct < LIM && s_gets(input[ct], SIZE) != NULL
            && input[ct][0] != '\0') {
       ptstr[ct] = input[ct]; /* 设置指针批向字符串 */
       ct++;
    }
    str_sort(ptstr, ct);
    puts("\nHere is the sorted list:\n");
    for (k = 0; k < ct; k++) {
        puts(ptstr[k]);        
    }
    return 0;
}

/* 字符串-指针- 排序函数 */

void str_sort(char * strings[], int num)
{
    char *temp;
    int k, top , seek;
    printf("original:\n");
    for (k = 0; k < num; k++) {
        puts(strings[k]);        
    }
    for (top = 0; top < num -1; top++) {
        for (seek = top + 1; seek < num; seek++) {
            if (strcmp(strings[top], strings[seek]) < 0) {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            } 
            printf("sub round: %d\n", seek);
            for (k = 0; k < num; k++) {
                puts(strings[k]);        
            }
        }
        printf("round: %d\n", top);
        for (k = 0; k < num; k++) {
            puts(strings[k]);        
        }
    }
}


char * s_gets(char * st, int n)
{
    char * ret_val;
    int i = 0;
    ret_val = fgets(st , n , stdin);
    if (ret_val) {
        while (st[i] != '\n' && st[i] != '\0') {
            i++;
        }
        if (st[i] == '\n') {
            st[i] = '\0';
        } else {
            while (getchar() != '\n') {
                continue;;
            }
        }
    }
    return ret_val;
}


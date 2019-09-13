/*
 * string_find.c - 给定一个指向以NULL结尾的指针列表的指针，在列表中的字符串中查找一个特定的字符
 */

#include <stdio.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0

int find_char(char ** strings, char value);
int find_char2(char ** strings, int value);


int main(void)
{
    char * str2[] = {"abc", "def"};
    char c = 'c'; 
    printf("find result: %d\n", find_char(str2, c));
    printf("find result: %d\n", find_char2(str2, c));
    return 0;
}
int find_char(char ** strings, char value)
{
    char * string; /* 我们当前正在查找的字符串 */
    while ((string = *strings++) != NULL) {
        /*
         * 观察字符串中的每个字符， 看看它是不是我们需要查找的那个
         */
        while (*string != '\0') {
            if (*string++ == value) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

int find_char2(char ** strings, int value) 
{

    assert(*strings != NULL);
    while (**strings != '\0') {
        if (*(*strings)++ == value) {
            return TRUE;
        }
    }
    strings++;
}


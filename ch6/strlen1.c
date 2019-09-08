/*
 * 计算一个字符串的长度
 */

#include <stdio.h>
size_t str_len(char * string) ;
int main(void)
{
    /*
     * 依次访问字符串的内容，计数字符数， 直到遇见NULL终止符
     */
    char *a = "ABC";
    printf("length a = %zu\n", str_len(a));

}

size_t str_len(char * string) 
{

    int length = 0;
    while (*string != '\0') {
        length += 1;
        string++;
    }
    return length;
}

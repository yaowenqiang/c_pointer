/*
 * 神秘函数，参数是一个0 - 100的值
 */

#include <stdio.h>
#include <stdlib.h>
void mystery(int n);
void binary_to_ascii(unsigned int value);
void binary_to_ascii_v2(unsigned int value);
int main(void)
{
    mystery(1);
    printf("%s\n", "xyz" + 1);
    printf("%c\n", "xyz" + 1);
    printf("%p\n", "xyz" + 1);
    printf("%c\n", ("xyz" + 1)[0]);
    binary_to_ascii_v2(111);
    binary_to_ascii(111);
    return 0;
}

void mystery(int n)
{
    n += 5;
    n /= 10;
    printf("%s\n", "****************" +10 - n);
}


void binary_to_ascii(unsigned int value) 
{
    unsigned int quotient;
    quotient = value / 10;
    if (quotient != 0) {
        binary_to_ascii(quotient);
    }

    putchar(value%10 + '0');
}

void binary_to_ascii_v2(unsigned int value) 
{
    
    putchar("0123456789ABCDEF" [value % 16]);
}

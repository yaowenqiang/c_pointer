/*
 * order.c - 指针运算中的优先级
 */

#include <stdio.h>
int data[2] = {100,200};
int moredata[2] = {300, 400};
int main(void)
{
    int *p1, *p2, *p3;
    p1 = p2 = data;
    p3 = moredata;
    printf("p1 %p\n", p1);
    printf("sizeof p1 %ld\n", sizeof p1);
    printf("value of *p1 %d\n", *p1);
    printf("value of *p1++ %d\n", *p1++);
    printf("p1 %p\n", p1);
    printf("p1++ %p\n", p1++);
    printf("p1 %p\n", p1);
    printf("%d\n", ((*p1)++));
    printf("%p\n", p1);
    printf("++p1 %p\n", ++p1);
    printf("%p\n", p1);
    printf("*p1   = %d,   *p2   = %d, *p3      = %d\n", *p1, *p2, *p3);
    printf("&p1   = %p,   &p2   = %p, &p3      = %p\n", p1, p2, p3);
    printf("*p1++ = %d, *++p2   = %d, (*p3) ++ = %d\n", *p1++, *++p2, (*p3)++);
    printf("&p1   = %p,   &p2   = %p, &p3      = %p\n", p1, p2, p3);
    printf("(*p1)++ = %d, *++p2   = %d, (*p3) ++ = %d\n", (*p1)++, *++p2, (*p3)++);
    printf("&p1   = %p,   &p2   = %p, &p3      = %p\n", p1, p2, p3);
    printf("*p1   = %d,   *p2   = %d, *p3      = %d\n", *p1, *p2, *p3);
    printf("&p1   = %p,   &p2   = %p, &p3      = %p\n", p1, p2, p3);
    return 0;
}

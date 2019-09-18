/*
 * fork.c gdb 多纯种调试
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int add(int x , int y)
{
    return x+y;
}

int test()
{
    int num = 0;
    pid_t pid = fork();
    if (pid == 0)
    {
        while(1) {
            num = add(1,2);
            printf("child pid %d num = %d\n", getpid(), num);
            sleep(1);
        }
        exit(0);
    }

    while(1) {
        num = add(10,20);
        printf("parent pid: %d num = %d\n", getpid(), num);
        sleep(1);
    }
    return 0;
}

int main(void)
{
    test();
    return 0;
}

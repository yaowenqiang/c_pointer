/*
 * debugme.c -- poorly writen program to debug
 * gdb debugme -q -- run gdb without licence info
 * gdb) run
 * gdb) backtrace
 * gdb) list 10, 24
 * gdb) list
 * gdb) print ary@10
 * gdb) print ary[1]@5
 * gdb) print i
 * gdb) print ary[i)
 * gdb) whatis i
 * gdb) whatis ary
 * gdb) whatis index_to_the_moon
 *
 *
 */

#include <stdio.h>
#define BIGNUM 5000

void index_to_the_moon(int ary[]);
int main(void)
{
    int intary[100];
    index_to_the_moon(intary);
    return 0;
}

void index_to_the_moon(int ary[])
{
    int i;
    for (i = 0; i < BIGNUM; i++) {
        ary[i] = i;
    }
}

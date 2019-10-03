/*
 * array_reference.c 
 */

#include <stdio.h>
int main(void)
{
    char * strings[1];
    strings[0] = &strings;
    return 0;
}

/*
 * queue demo
 */

#include <stdio.h>
#include "queue1.h"

int main(void)
{
    for (int i = 0; i < 1000; i++) {
        insert(i); 
    }
    //rm();
    //rm();
    //rm();
    printf("%d\n", first());
    return 0;
}

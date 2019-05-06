/*
 * enum_test.c
 */

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    enum corvid {magpie, raven, jay, corvid_num,};
    char const*const animal[corvid_num] = {
        [raven] = "raven",
        [magpie] = "magpie",
        [jay] = "jay"
    };

    for (int i = 0; i < corvid_num; i++) {
        printf("%s\n", animal[i]);
    }
    return 0;
}

/*
 * enum_test.c
 */

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    enum corvid {magpie, raven, jay, chough,corvid_num, };
    char const*const animal[corvid_num] = { [raven] = "raven",
        [magpie] = "magpie",
        [jay] = "jay"
    };

    for (int i = 0; i < corvid_num; i++) {
        printf("%s\n", animal[i]);
    }

    enum {p0 = 1, p1 = 2*p0, p2 = 2*p1, p3=2*p2,};
    printf("%d\n", p0);
    printf("%d\n", p1);
    printf("%d\n", p2);
    printf("%d\n", p3);

    // for (int i = 0; i < 3; i++) {
        // printf("%d\n", i);
    // }
    //

    signed const o42 = 42;
    enum {
        b42  = 42,
        //c52 = o42 + 10,//TODO error, o42 is a object 
        b52 = b42 + 10,//TODO all right, b42 is an integer
    };
    printf("%d\n", o42);
    printf("%d\n", b42);
    //printf("%d\n", c52);
    printf("%d\n", b52);


# define CORVID_NAME /**/          
(char const*const[corvid_num]) { \
    [chough] = "chough",         \
    [raven] = "raven",           \
    [magpie] = "magpie",         \
    [jay] = "jay",               \
}

for (unsigned i = 0; i < corvid_num; ++i) {
    printf("Corvid %u is the %s\n", i, CORVID_NAME[i]); //TODO
}

    return 0;
}

/*
 * const_const.c
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char const*const animal[3] = {
        "raven",
        "magpie",//鹊
        "jay",//松鸡
    };
    const char* animal2[3];
    animal2[0] = "raven";
    animal2[1] = "magpie";//鹊
    animal2[2] = "jay";//松鸡

    char const*const pronoun[3] = {
        "we",
        "you",
        "they"
    };
    char const*const oridinal[3] = {
        "first",
        "second",
        "theird"
    };


    for(unsigned i = 0; i < 3; ++i) {
        printf("Corvid %u is the %s\n", i, animal[i]);
    }
    for(unsigned i = 0; i < 3; ++i) {
        printf("Corvid %u is the %s\n", i, animal2[i]);
    }

    for(unsigned i = 0; i < 3; ++i) {
        printf("%s plural pronoun is %s\n", oridinal[i], pronoun[i]);
    }
    return 0;
}

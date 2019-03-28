/*
 * errtest.c - Test program for error-handling library
 */

#include <stdio.h>
#include <stdlib.h>
#include "liberr.h"

#define ERR_QUIT_SKIP 1
#define LOG_QUIT_SKIP 1

int main(void)
{
    FILE *pf;
    puts("Testing err_ret");
    if((pf = fopen("foo", "r")) == NULL) {
        err_ret("%s %s", "err_ret:" , "failed to open fooo");
    }

    puts("Testing log_ret");
    if((pf = fopen("foo", "r")) == NULL) {
        log_ret("errtest.log", "%s %s", "err_ret:" , "failed to open fooo");
    }

    #ifndef ERR_QUIT_SKOP 
    puts("Testing err_quit");
    if((pf = fopen("foo", "r")) == NULL) {
        err_quit("errtest.log", "%s %s", "err_ret:" , "failed to open fooo");
    }
    #endif

    #ifndef LOG_QUIT_SKOP 
    puts("Testing log_quit");
    if((pf = fopen("foo", "r")) == NULL) {
        log_ret("errtest.log", "%s %s", "err_ret:" , "failed to open fooo");
    }
    #endif
}

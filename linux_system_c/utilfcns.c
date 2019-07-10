#include <stdlib.h>
#include <unistd.h>
#include <curses.h>
#include <errno.h>
#include "utilfcns.h"
void app_init()
{
    if ((stdscr = initscr()) == NULL) {
        perror("initscr") ;
        exit(EXIT_FAILURE);
    }
}

void app_exit()
{
    endwin();
}

/*
 * initcurs.c
 */

#include <stdlib.h>
#include <unistd.h>
#include <curses.h>
#include <errno.h>

int main(void)
{
    if ((initscr()) == NULL) {
        perror("initscr");
        exit(EXIT_FAILURE);
    }
    printw("This is a curses window\n");
    refresh();
    sleep(3);
    printw("Going bye-bye now\n");
    refresh();
    sleep(3);
    endwin();
    exit(0);
}

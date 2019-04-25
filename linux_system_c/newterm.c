/*
 * newterm.c - curses initialization and termination
 */

#include <stdlib.h>
#include <unistd.h>
#include <curses.h>
#include <errno.h>

int main(void)
{
    SCREEN *scr;
    if ((scr = newterm(NULL, stdout, stdin)) == NULL) {
        perror("newterm");
        exit(EXIT_FAILURE);

    }

    if (set_term(scr) == NULL) {
        perror("set_term");
        endwin();
        delscreen(scr);
        exit(EXIT_FAILURE);
    }
    printw("This curses window created with newterm()\n");
    refresh();
    sleep(3);
    endwin();
    delscreen(scr);
    exit(0);

}

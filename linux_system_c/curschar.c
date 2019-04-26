/*
 * curschar.c - curses character output functions
 */

#include <stdlib.h>
#include <unistd.h>
#include <curses.h>
#include <errno.h>
#include <utillfcns.h>

int main(void)
{
    app_init();
    addch("X");
    addch("Y" | A_REVERSE);
    mvaddch(2, 1, '2' | A_BOLD);
    refresh();
    sleep(3);

    clear();
    waddch(stdscr, "X");
    waddch(stdscr, "Y");
    mvwaddch(stdscr, 2, 1, 'Z' | A_BOLD);
    refresh();
    sleep(3);

    app_exit();
    exit(0);

    waddch(2, 1, 'Z' | A_BOLD);
    
        
}
























































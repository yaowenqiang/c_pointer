/*
 * curschar.c - curses character output functions
 */

#include <stdlib.h>
#include <unistd.h>
#include <curses.h>
#include <errno.h>
WINDOW *stdscr;
void app_init();
void app_exit();

int main(void)
{
    app_init();
    addch('X');
    addch('Y' | A_REVERSE);
    addch('Y');
    mvaddch(2, 1, '2' | A_BOLD);
    refresh();
    sleep(3);

    clear();
    waddch(stdscr, 'X');
    waddch(stdscr, 'Y');
    mvwaddch(stdscr, 2, 1, 'Z' | A_BOLD);
    refresh();
    sleep(3);

    app_exit();
    exit(0);
        
}

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

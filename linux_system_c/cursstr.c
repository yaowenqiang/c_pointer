/*
 * cursstr.c - curses string output functions
 */

#include <stdlib.h>
#include <unistd.h>
#include <curses.h>
#include <errno.h>
WINDOW *stdscr;
void app_init();
void app_exit();
int err_quit(char *msg);

int main(void)
{
    int xmax, ymax;
    WINDOW *tmpwin;
    
    app_init();
    getmaxyx(stdscr, ymax, xmax);
    addstr("Using the *str() family\n");
    hline(ACS_HLINE, xmax);
    mvaddstr(3, 0, "This string appers in full\n");
    mvaddnstr(5, 0, "This string is truncated\n", 15);
    refresh();
    sleep(3);
    if ((tmpwin = newwin(0,0,0,0)) == NULL) {
        err_quit("newwin");
    }
    mvwaddstr(tmpwin, 1,1, "This message should appear in a new iwndow");
    wborder(tmpwin, 0,0,0,0,0,0,0,0);
    touchwin(tmpwin);
    wrefresh(tmpwin);
    sleep(3);
    delwin(tmpwin);

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
int err_quit(char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

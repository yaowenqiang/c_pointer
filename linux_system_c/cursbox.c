/*
 * cursbox.c - curses box  drawing functions
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
    
    app_init();
    getmaxyx(stdscr, ymax, xmax);

    mvaddch(0,0, ACS_ULCORNER);
    hline(ACS_HLINE, xmax - 2);

    mvaddch(ymax -1,0, ACS_LLCORNER);
    hline(ACS_HLINE, xmax - 2);

    mvaddch(0,xmax - 1, ACS_URCORNER);
    hline(ACS_VLINE, ymax - 2);

    mvvline(1, xmax -1, ACS_VLINE, ymax -2);
    mvaddch(ymax -1, xmax -1, ACS_LRCORNER);

    mvprintw(ymax/3 -1, (xmax -30) /2, "border drawn the hard way");
    refresh();
    sleep(3);
    clear();
    wborder(stdscr, 
            ACS_VLINE | A_BOLD, 
            ACS_VLINE | A_BOLD, 
            ACS_HLINE | A_BOLD,
            ACS_HLINE | A_BOLD,
            ACS_ULCORNER | A_BOLD, 
            ACS_URCORNER | A_BOLD,
            ACS_LLCORNER | A_BOLD, 
            ACS_LRCORNER | A_BOLD);

    mvprintw(ymax/3 -1, (xmax -25) /2, "border drawn with wborder");
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
    /*
    if (set_term(stdscr) == NULL) {
        perror("set_term");
        endwin();
        delscreen(stdscr);
    }*/
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

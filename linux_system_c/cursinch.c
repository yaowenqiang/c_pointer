/*
 * cursinch.c - curses character input function
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
    int c, i = 0; 
    int xmax, ymax;
    char str[80];
    WINDOW *pwin;
    app_init();
    crmode();
    getmaxyx(stdscr, ymax, xmax);
    if ((pwin = subwin(stdscr, 3, 40, ymax / 3, (xmax -40) /2 )) == NULL) {
        err_quit("subwin");
    }
    box(pwin, ACS_VLINE, ACS_HLINE);
    
    mvwaddstr(pwin, 1, 1, "Password: ");

    noecho();
    while ((c = getch()) != '\n' && i < 80) {
        str[i++] = c;
        waddch(pwin, '*');
        wrefresh(pwin);
    }
    echo();
    str[i] = '\0';
    wrefresh(pwin);
    mvwprintw(pwin, 1, 1, "You typed: %s\n", str);
    wrefresh(pwin);
    sleep(3);
    delwin(pwin);
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

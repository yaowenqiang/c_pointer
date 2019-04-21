/*
 * setraw.c - Illustrate raw mode
 */

#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void err_quit(char *msg);
void err_reset(char *msg, struct termios *flags);
static void sig_caught(int signum);

int main(void)
{
    struct termios old_flags, new_flags;
    int i, fd;
    char c;

    /* Set up a signal handler */

    if (signal(SIGINT, sig_caught) == SIG_ERR) {
        err_quit("Failed to set up SIGINT handler");
    }

    if (signal(SIGQUIT, sig_caught) == SIG_ERR) {
        err_quit("Failed to set up SIGQUIT handler");
    }
    if (signal(SIGTERM, sig_caught) == SIG_ERR) {
        err_quit("Failed to set up SIGTERM handler");
    }

    fd = fileno(stdin);

    /* Set up raw/non-canonical mode */

    tcgetattr(fd, &old_flags);
    new_flags = old_flags;

    new_flags.c_lflag &= ~ (ICANON | ECHO | ISIG);
    new_flags.c_lflag &= ~ (BRKINT | ICRNL);
    new_flags.c_oflag &= ~OPOST;
    new_flags.c_cc[VTIME] = 0;
    new_flags.c_cc[VMIN] = 1;
    
    if (tcsetattr(fd, TCSAFLUSH, &new_flags) < 0) {
        err_reset("Failed to change attributes", &old_flags);
    }

    /* Process keystrokes untill DELETE key is pressed */
    puts("In RAW mode, Press DELETE key to exit");
    while ((i = read(fd, &c, 1)) == 1) {
        if ((c &= 255) == 0177) {
            break;
        }
        printf("%o\n", c);
    }
    /* Restore original terminal attributes */
    tcsetattr(fd, TCSAFLUSH, &old_flags);
    exit(EXIT_SUCCESS);

}

void sig_caught(int signum)
{
    printf("Signal caught: %d\n", signum);
}

void err_quit(char *msg)
{
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

void err_reset(char *msg, struct termios *flags)
{
    fprintf(stderr, "%s\n", msg);
    tcsetattr(fileno(stdin), TCSANOW, flags);
    exit(EXIT_FAILURE);
}

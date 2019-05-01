/*
 * noecho.c - Using termios to disable key echo
 */

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

#define PASS_LEN 8

void err_quit(char *msg, struct termios flags);

int main(void)
{
    struct termios old_flags, new_flags;
    char password[PASS_LEN + 1];
    int retval;

    /* Make sure stdin is a terminal */
    if (!isatty(STDIN_FILENO)) {
        fprintf(stderr, "Not a terminal\n");
        exit(EXIT_FAILURE);
    }

    /* Get the current terminal settings */
    tcgetattr(fileno(stdin), &old_flags);
    new_flags = old_flags;

    /* Turn off local echo, but apss the newlines through */

    //new_flags.c_lflag &= -ECHO;
    //new_flags.c_lflag |= ECHONL;
    new_flags.c_lflag = ~ (ICANON | ECHO);

    /*
     * Did it work ? 
     */

    retval = tcsetattr(fileno(stdin), TCSAFLUSH, &new_flags);
    printf("retval %d\n", retval);

    if (retval != 0) {
        err_quit("Failed to set attributes", old_flags);
    }

    /* Dit the settings change? */
    tcgetattr(fileno(stdin), &new_flags);
    if (new_flags.c_lflag & ECHO) {
        err_quit("Failed to turn off ECHO", old_flags);
    }
    if (!new_flags.c_lflag & ECHONL) {
        err_quit("FAiled to turn on ECHONL", old_flags);
    }
    printf("Enter password:\n");
    fgets(password, PASS_LEN + 1, stdin);
    printf("You typed: %s\n",password);
    /* Restore the old termios settings */
    tcsetattr(fileno(stdin), TCSANOW, &old_flags);
    exit(EXIT_SUCCESS);
}

void err_quit(char *msg, struct termios flags)
{
    fprintf(stderr, "%s\n", msg);
    tcsetattr(fileno(stdin), TCSAFLUSH, &flags);
    exit(EXIT_FAILURE);

}

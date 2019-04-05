/*
 * dup.c - Using dup2 to redirect stdou 
 */
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h> 
#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>

void print_line(int n);

int main(void)
{
  
    int fd;
    /* Scribble on stdout */
    print_line(STDOUT_FILENO); // 1
    print_line(1);
    print_line(2);
    print_line(3);
    /* Redirect stdout to the file junk.out */
    if ((fd = open("junk.txt", O_WRONLY | O_CREAT , 0666)) < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    print_line(30);
    if ((dup2(fd, STDOUT_FILENO)) < 0) {
        perror("dup2");
        exit(EXIT_FAILURE);
    }

    /* Scribble on redirected stdout */
    print_line(4);
    print_line(5);
    print_line(6);
    close(fd);
    close(STDOUT_FILENO);
    exit(EXIT_SUCCESS);
}

void print_line(int n)
{
    char buf[80];
    snprintf(buf, sizeof(buf), "LIne #%d\n", n);
    write(STDOUT_FILENO, buf, strlen(buf));
}


/*
 * piperw.c - The correct way to open a pipe and for a child process
 */

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>  
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>

void err_quit(char *msg);

int main(int argc, char *argv[])
{
   int fd[2]; /* File descriptor array for the pipe */
   int fdin; /* descript for input file */
   char buf[BUFSIZ];
   int pid, len;

   /* Create the pipe */
   if ((pipe(fd)) < 0) {
       err_quit("pipe");
   } 

   /* Fork and close the appropriate descriptors */
   if ((pid = fork()) <0) {
       err_quit("fork");
   }

   if (pid == 0) {
       /* Child is reader, close the write descriptor */
       close(fd[1]);
       while ((len = read(fd[0], buf, BUFSIZ)) >0) {
           write(STDOUT_FILENO, buf, len);
       }
       close(fd[0]);
   } else {
       /* Parent is writer , close the read descriptors */
       close(fd[0]);
       if ((fdin = open(argv[1], O_RDONLY)) < 0) {
           perror("open");
           /* Send something since we couldn't open the input */
           write(fd[1], "123\n", 4);
       } else {
           while ((len = read(fdin, buf, BUFSIZ))) {
                write(fd[1], buf, len);
           }
           close(fdin);
       }
       /* close the write descriptor */
       close(fd[1]);
   }
   /* reap the exit status */
   waitpid(pid, NULL, 0);
   exit(EXIT_SUCCESS);
}


void err_quit(char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

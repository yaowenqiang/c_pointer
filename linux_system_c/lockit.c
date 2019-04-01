/*
 * lockit.c -Set file locks on a file
 */

#include <unistd.h>
#include <sys/file.h>
#include <sys/types.h>  
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

/* Sets lock of type on descriptor fd */
void setlock(int fd, int type);

int main(int argc, char const* argv[])
{
  int fd;
  /* Open the file */
  fd = open(argv[1], O_RDWR | O_CREAT, 0666);
  if (fd <0) {
      perror("open");
      exit(EXIT_FAILURE);
  }
  /* Set read lock */
  setlock(fd, F_RDLCK);
  printf("PID %d unlocked %s\n", getpid(), argv[1]);
  getchar();
  return 0;
}

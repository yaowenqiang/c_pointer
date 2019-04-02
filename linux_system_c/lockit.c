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
  printf("PID %d locked %s\n", getpid(), argv[1]);
  getchar();

  /* Unlock */
  setlock(fd, F_UNLCK);
  printf("PID %d unlock %s\n",getpid(), argv[1]);
  getchar();

  /* Set write lock */
  setlock(fd, F_WRLCK);
  printf("PID %d write locked  %s\n",getpid(), argv[1]);
  getchar();
  close(fd);
  exit(EXIT_SUCCESS);

}

void setlock(int fd, int type) {
    struct flock lock;
    char msg[80];

    /* Describe the lock we want */

    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 1; /* Lock a single byte */
    while(1) {
        lock.l_type = type;
        /* Set the lock and return to caller */
        if ((fcntl(fd, F_SETLK, &lock)) == 0) {
            return;
        }

        /* Find out why we counldn't set the lock */

        fcntl(fd, F_GETLK, &lock);
        if (lock.l_type != F_UNLCK) {
            switch(lock.l_type) {
                case(F_RDLCK):
                    sprintf(msg, "read lock already set by %d\n", lock.l_pid);
                    break;
                case(F_WRLCK):
                    sprintf(msg, "write lock already set by %d\n", lock.l_pid);
                    break;
            }
            puts(msg);
            getchar();
        }
    }
}

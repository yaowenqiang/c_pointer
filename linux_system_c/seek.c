/*
 * seek.c - Using lseek, fsync, and ftruncate
 */

#include <unistd.h> 
#include <sys/stat.h>
#include <sys/types.h>  
#include <fcntl.h>  
#include <time.h> 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)

{
    char ftmp[ ] = "tmpxxxxxx";
    char buf[10];
    struct stat statbuf;
    int infd, outfd;
    /*open the input file */

    if ((infd = open("devices.txt", O_RDONLY) < 0))  {
        perror("open devices.txt");
        exit(EXIT_FAILURE);
    }
    /* create a temporary file for output */
    if ((outfd = mkstemp(ftmp)) < 0) {
        perror("mkstemp");
        exit(EXIT_FAILURE);
    }

    printf("output file is %s\n", ftmp);

    lseek(infd, 100, SEEK_SET);

    /*
     * copy the first ten out of every 100 bytes
     * to the output file
     */

    for (int i = 0; i < 10; ++i) {
       read(infd, buf, 10);
       write(outfd, buf , 10);
       lseek(infd, 90, SEEK_CUR); /* jump forward 90 bytes */
    }

    /* show size before and after ftruncate */
    fstat(outfd, &statbuf);
    printf("before ftruncate, %s is %ld bytes\n", ftmp, statbuf.st_size);
    ftruncate(outfd, statbuf.st_size / 2);
    fsync(outfd);
    fstat(outfd, &statbuf);
    printf("after ftruncate, %s is %ld bytes\n", ftmp, statbuf.st_size);
    /* close "em up and get outta here */
    close(infd);
    close(outfd);
    exit(EXIT_SUCCESS);
}

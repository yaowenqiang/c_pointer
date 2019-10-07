#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main(void)
{
    int ct1 = clock() / CLOCKS_PER_SEC;
    //sleep(10);
    int ct2 = clock() / CLOCKS_PER_SEC;
    printf("%d\n", ct2 - ct1);
    //time_t *pt;
    time_t pt;
    time(&pt);

    printf("time = %ld\n", pt);

    printf("%s\n",ctime(&pt));

    struct tm * timeinfo;
    timeinfo = localtime(&pt);
    printf("today is %d\n", timeinfo->tm_mday);
    return 0;
}

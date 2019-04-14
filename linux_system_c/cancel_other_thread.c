/*
 * cancel_other_thread.c - C program to demonstrate cancellation of another thread
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

int counter = 0;

pthread_t tmp_thread;

void* func(void* p)
{
    while (1) {
        printf("thread number one, counter: %d\n", counter);
        sleep(1);
        counter++;

        if (counter == 2) {
            pthread_cancel(tmp_thread);
            pthread_exit(NULL);
        }
    }
}


void* func2(void* p)
{
    tmp_thread = pthread_self();
    while (1) {
        printf("thread number two, counter: %d\n", counter);
        sleep(1);
        //counter++;
    }
}

int main()
{
    pthread_t thread_one, thread_tow;

    pthread_create(&thread_one, NULL,func, NULL);
    pthread_create(&thread_tow, NULL,func2, NULL);
    
    pthread_join(thread_one, NULL);
    pthread_join(thread_tow, NULL);
}

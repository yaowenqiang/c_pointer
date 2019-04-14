/*
 * cancel_thread.c - C program to demonstrate cancellation of self thread
 */

#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void* calls(void* str)
{
    // To exit the current threado
    // pthread_self() return the particula thread id
    printf("GeekForGeeks");
    pthread_cancel(pthread_self());
    return NULL;
}

int main()
{
    //NULL when no attribute
    pthread_t thread;

    //calls is a function name

    pthread_create(&thread, NULL, calls ,NULL);

    //waiting for when thread is completed
    pthread_join(thread, NULL);

    return 0;
}




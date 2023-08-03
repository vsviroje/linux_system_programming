#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/wait.h>

void *ThreadProc1(void *ptr)
{
    for (int i = 1; i <= 500; i++)
    {
        printf("Thread1 with counter:%d\n", i);
    }
}

void *ThreadProc2(void *ptr)
{
    for (int i = 500; i > 0; i--)
    {
        printf("Thread2 with counter:%d\n", i);
    }
}

// Multithread demonstration
int main()
{
    pthread_t tid1, tid2;
    int ret1 = 0, ret2 = 0;
    ret1 = pthread_create(&tid1,       // Address of pthread_t structure object
                          NULL,        // Thread attributes
                          ThreadProc1, // Address of callback function
                          NULL);       // Parameters to callback function

    if (ret1 != 0)
    {
        printf("Failed to create thread1\n");
        return -1;
    }

    ret2 = pthread_create(&tid2,       // Address of pthread_t structure object
                          NULL,        // Thread attributes
                          ThreadProc2, // Address of callback function
                          NULL);       // Parameters to callback function

    if (ret2 != 0)
    {
        printf("Failed to create thread2\n");
        return -1;
    }

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("End of main thread\n");

    return 0;
}

/*
gcc -pthread ProcessSystem68.c
*/
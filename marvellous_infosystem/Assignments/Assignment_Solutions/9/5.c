#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/wait.h>

//Not sure sched_yield() valid way or not because pthread_yield() is deprecated

void *ThreadProc1(void *ptr)
{
    for (int i = 1; i <= 10; i++)
    {
        printf("Thread1 with counter:%d\n", i);
        if (i % 2 == 0)
        {
            sched_yield();
        }
    }
}

void *ThreadProc2(void *ptr)
{
    for (int i = 1; i <= 10; i++)
    {
        printf("Thread2 with counter:%d\n", i);
        if (i % 2 == 0)
        {
            sched_yield();
        }
    }
}

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
        printf("Failed to create thread2\n");
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

    printf("Created thread1 id:%ld\n", tid1);
    printf("Created thread2 id:%ld\n", tid2);

    for (int i = 1; i <= 10; i++)
    {
        printf("Main Thread with counter:%d\n", i);
        if (i % 2 == 0)
        {
            sched_yield();
        }
    }

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    printf("End of main thread\n");

    return 0;
}

/*
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/9$ ./a.out 
Created thread1 id:140515676669696
Thread2 with counter:1
Thread2 with counter:2
Thread1 with counter:1
Thread2 with counter:3
Created thread2 id:140515668276992
Thread1 with counter:2
Main Thread with counter:1
Thread2 with counter:4
Main Thread with counter:2
Thread1 with counter:3
Thread1 with counter:4
Thread1 with counter:5
Thread1 with counter:6
Thread1 with counter:7
Thread1 with counter:8
Thread1 with counter:9
Thread1 with counter:10
Main Thread with counter:3
Main Thread with counter:4
Thread2 with counter:5
Thread2 with counter:6
Main Thread with counter:5
Main Thread with counter:6
Thread2 with counter:7
Thread2 with counter:8
Thread2 with counter:9
Thread2 with counter:10
Main Thread with counter:7
Main Thread with counter:8
Main Thread with counter:9
Main Thread with counter:10
End of main thread
*/
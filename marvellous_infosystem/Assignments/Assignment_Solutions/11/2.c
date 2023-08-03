#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/wait.h>

void *ThreadProc(void *no)
{
    int temp = *(int *)no;
    pthread_attr_t attr;
    int ret, tempVal;

    printf("thread%d created\n", temp + 1);

    ret = pthread_getattr_np(pthread_self(), &attr);
    if (ret != 0)
    {
        printf("error in pthread_getattr_np");
        return NULL;
    }

    ret = pthread_attr_getscope(&attr, &tempVal);
    if (ret != 0)
    {
        printf("error in pthread_attr_getscope");
        return NULL;
    }

    printf("Thread:%d Scope= %s\n", temp + 1, (tempVal == PTHREAD_SCOPE_SYSTEM) ? "PTHREAD_SCOPE_SYSTEM" : (tempVal == PTHREAD_SCOPE_PROCESS) ? "PTHREAD_SCOPE_PROCESS"
                                                                                                                                              : "Don't know");

    pthread_exit(NULL);
}

// Multithread demonstration
int main()
{
    void *(*tp[4])(void *) = {ThreadProc, ThreadProc, ThreadProc, ThreadProc};

    pthread_t tid[4];
    pthread_attr_t attr;
    int ret[0], retTemp;
    int i = 0;

    retTemp = pthread_attr_init(&attr);
    if (retTemp == -1)
    {
        printf("error in pthread_attr_init");
        return -1;
    }

    for (i = 0; i < 4; i++)
    {
        ret[i] = pthread_create(&tid[i],    // Address of pthread_t structure object
                                &attr,      // Thread attributes
                                tp[i],      // Address of callback function
                                (int *)&i); // Parameters to callback function

        if (ret[i] != 0)
        {
            printf("Failed to create thread%d\n", i + 1);
            tid[i] = 0;
            continue;
        }

        printf("%d ThreadId:%ld\n", i + 1, tid[i]);
    }

    for (i = 0; i < 4; i++)
    {
        if (tid[i] != 0)
        {
            pthread_join(tid[i], NULL);
        }
    }

    printf("End of main thread\n");
    pthread_exit(NULL);

    return 0;
}

/*
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/11$ gcc -pthread 2.c 
2.c: In function ‘ThreadProc’:
2.c:16:11: warning: implicit declaration of function ‘pthread_getattr_np’; did you mean ‘pthread_attr_init’? [-Wimplicit-function-declaration]
     ret = pthread_getattr_np(pthread_self(), &attr);
           ^~~~~~~~~~~~~~~~~~
           pthread_attr_init
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/11$ ./a.out 
1 ThreadId:139896229537536
thread1 created
2 ThreadId:139896221144832
thread3 created
Thread:1 Scope= PTHREAD_SCOPE_SYSTEM
3 ThreadId:139896144525056
thread4 created
Thread:3 Scope= PTHREAD_SCOPE_SYSTEM
4 ThreadId:139896136132352
thread4 created
Thread:4 Scope= PTHREAD_SCOPE_SYSTEM
Thread:4 Scope= PTHREAD_SCOPE_SYSTEM
End of main thread
*/
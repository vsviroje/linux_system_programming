#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/wait.h>

void *ThreadProc(void *no)
{
    int temp = *(int *)no;
    printf("thread%d created\n", temp + 1);
    pthread_exit(NULL);
}

// Multithread demonstration
int main()
{
    void *(*tp[4])(void *) = {ThreadProc, ThreadProc, ThreadProc, ThreadProc};

    pthread_t tid[4];
    int ret[0];
    int i = 0;
    for (i = 0; i < 4; i++)
    {
        ret[i] = pthread_create(&tid[i],    // Address of pthread_t structure object
                                NULL,       // Thread attributes
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
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/11$ gcc -pthread 1.c 
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/11$ ./a.out 
1 ThreadId:139811392427776
thread2 created
2 ThreadId:139811384035072
thread3 created
thread3 created
3 ThreadId:139811375642368
4 ThreadId:139811365054208
thread1 created
End of main thread
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/wait.h>

void *ThreadProc(void *no)
{
    printf("thread Number:%d\n", *(int*)no);
}

// Multithread demonstration
int main()
{
    pthread_t tid;
    int ret = 0;
    int no = 11;
    ret = pthread_create(&tid,       // Address of pthread_t structure object
                         NULL,       // Thread attributes
                         ThreadProc, // Address of callback function
                         (int *)&no); // Parameters to callback function

    if (ret != 0)
    {
        printf("Failed to create thred\n");
        return -1;
    }

    printf("Created thred id:%ld\n", tid);

    pthread_join(tid, NULL);

    printf("End of main thread\n");

    return 0;
}

/*

*/
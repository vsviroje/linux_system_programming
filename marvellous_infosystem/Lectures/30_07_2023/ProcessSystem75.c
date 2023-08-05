#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/wait.h>

/*
prototype to use thread func
void *NameOfFunction(void *VariableName){}
*/

void *ThreadProc(void *no)
{
    int temp = *(int *)no;
    printf("thread Number:%d\n", temp);
    pthread_exit(++temp); // return value
}

// Multithread demonstration
int main()
{
    pthread_t tid;
    int ret = 0;
    int no = 11;
    int retValue = 0;

    ret = pthread_create(&tid,        // Address of pthread_t structure object
                         NULL,        // Thread attributes
                         ThreadProc,  // Address of callback function
                         (int *)&no); // Parameters to callback function...use array to send multiple paramenters

    if (ret != 0)
    {
        printf("Failed to create thred\n");
        return -1;
    }

    pthread_join(tid,&retValue);
    printf("Created thred id:%ld and retValue:%d\n", tid, retValue);

    printf("End of main thread\n");

    return 0;
}

/*
gcc -pthread ProcessSystem68.c
*/
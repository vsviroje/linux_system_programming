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

void *ThreadProc(void *ptr)
{
    printf("inside thred\n");
}

// Multithread demonstration
int main()
{
    pthread_t tid;
    int ret = 0;
    ret = pthread_create(&tid,       // Address of pthread_t structure object
                         NULL,       // Thread attributes
                         ThreadProc, // Address of callback function
                         NULL);      // Parameters to callback function

    if (ret != 0)
    {
        printf("Failed to create thred\n");
        return -1;
    }

    printf("Created thred id:%ld\n",tid);

    return 0;
}

/*
gcc -pthread ProcessSystem68.c
*/
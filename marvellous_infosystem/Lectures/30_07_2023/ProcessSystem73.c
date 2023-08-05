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

void *ThreadProc1(void *ptr)
{
    char buffer[512] = {'\0'};
    int iCnt = 0, iRet = 0, i = 0, fd = 0;

    fd = open("Demo.txt", O_RDONLY);

    while ((iRet = read(fd, buffer, sizeof(buffer))) != 0)
    {
        for (i = 0; i < iRet; i++)
        {
            if ((buffer[i] >= 'A') && (buffer[i] <= 'Z'))
            {
                iCnt++;
            }
        }
    }

    printf("Thread1|Num of Capital case :%d\n", iCnt);

    close(fd);

    pthread_exit(NULL);
}

void *ThreadProc2(void *ptr)
{
    char buffer[512] = {'\0'};
    int iCnt = 0, iRet = 0, i = 0, fd = 0;

    fd = open("Demo.txt", O_RDONLY);

    while ((iRet = read(fd, buffer, sizeof(buffer))) != 0)
    {
        for (i = 0; i < iRet; i++)
        {
            if ((buffer[i] >= 'a') && (buffer[i] <= 'z'))
            {
                iCnt++;
            }
        }
    }

    printf("Thread2|Num of Small case :%d\n", iCnt);

    close(fd);

    pthread_exit(NULL);
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
        printf("Failed to create thred1\n");
        return -1;
    }

    printf("Created thred1 id:%ld\n", tid1);

    ret2 = pthread_create(&tid2,       // Address of pthread_t structure object
                          NULL,        // Thread attributes
                          ThreadProc2, // Address of callback function
                          NULL);       // Parameters to callback function

    if (ret2 != 0)
    {
        printf("Failed to create thred2\n");
        return -1;
    }

    printf("Created thred2 id:%ld\n", tid2);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("End of main thread\n");
    pthread_exit(NULL);

    return 0;
}

/*
gcc -pthread ProcessSystem72.c
*/
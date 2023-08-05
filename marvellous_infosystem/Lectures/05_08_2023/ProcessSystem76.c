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

int Counter = 0;//shared resource

void *ThreadProc(void *no)
{
    int i = 0;
    Counter++;
    printf("Thread executed with counter:%d\n", Counter);
    for (i = 0; i < 0xFFFFFFFF; i++)
        ;
    printf("Thread completed with counter:%d\n", Counter);

    pthread_exit(NULL);
}

// Multithread demonstration
int main()
{
    pthread_t tid1, tid2;
    int ret1 = 0, ret2 = 0;

    ret1 = pthread_create(&tid1,      // Address of pthread_t structure object
                          NULL,       // Thread attributes
                          ThreadProc, // Address of callback function
                          NULL);      // Parameters to callback function...use array to send multiple paramenters

    if (ret1 != 0)
    {
        printf("Failed to create thred\n");
        return -1;
    }

    ret2 = pthread_create(&tid2,      // Address of pthread_t structure object
                          NULL,       // Thread attributes
                          ThreadProc, // Address of callback function
                          NULL);      // Parameters to callback function...use array to send multiple paramenters

    if (ret2 != 0)
    {
        printf("Failed to create thred\n");
        return -1;
    }

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("End of main thread\n");

    return 0;
}

/*
vsviroje@viroje-Inspiron-15-7000-Gaming:~/Documents/Marvellous-LSP-2023/Lecture/05_08_2023$ gcc ProcessSystem76.c -lpthread 
vsviroje@viroje-Inspiron-15-7000-Gaming:~/Documents/Marvellous-LSP-2023/Lecture/05_08_2023$ ./a.out 
Thread executed with counter:1
Thread executed with counter:2
Thread completed with counter:2
Thread completed with counter:2
End of main thread
*/
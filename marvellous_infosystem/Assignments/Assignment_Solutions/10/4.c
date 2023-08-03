#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/wait.h>

void *ThreadProc(void *no)
{
    int temp = *(int *)no;
    printf("thread Number:%d\n", temp);
    pthread_exit(++temp); // return value
}

int main()
{
    pthread_t tid;
    int ret = 0;
    int no = 11;
    void *retValue = 0;

    ret = pthread_create(&tid,        // Address of pthread_t structure object
                         NULL,        // Thread attributes
                         ThreadProc,  // Address of callback function
                         (int *)&no); // Parameters to callback function...use array to send multiple paramenters

    if (ret != 0)
    {
        printf("Failed to create thred\n");
        return -1;
    }

    pthread_join(tid, &retValue);
    printf("Created thred id:%ld and retValue:%d\n", tid, (int)retValue);

    printf("End of main thread\n");

    return 0;
}

/*
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/10$ gcc -pthread 4.c -w
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/10$ ./a.out 
thread Number:11
Created thred id:139746986874624 and retValue:12
End of main thread
*/
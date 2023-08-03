#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/wait.h>

void *ThreadProc(void *ptr)
{
    pthread_t tid=pthread_self();
    printf("inside thread and threadId:%ld\n",tid);
}

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

    printf("Created thred id:%ld\n", tid);

    return 0;
}

/*
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/10$ gcc -pthread 5.c 
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/10$ ./a.out 
Created thred id:139916391167744
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/10$ ./a.out 
Created thred id:139784105293568
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/10$ ./a.out 
Created thred id:140363342219008
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/10$ ./a.out 
Created thred id:140122446509824
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/10$ ./a.out 
Created thred id:139841038882560
inside thread and threadId:139841038882560
inside thread and threadId:139841038882560
*/
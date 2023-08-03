#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/wait.h>

void *ThreadProc(void *ptr)
{
    printf("inside thred\n");
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
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/10$ gcc -pthread 1.c
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/10$ ./a.out
Created thred id:140545063364352
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/10$ ./a.out
Created thred id:140234905896704
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/10$ ./a.out
Created thred id:140507130590976
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/10$ ./a.out
Created thred id:140419883525888
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/10$ ./a.out
Created thred id:140410997294848
inside thred
inside thred
*/
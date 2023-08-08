#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/shm.h>

// Shared memory example
// server
int main()
{
    int shmid = 0;
    int shmSize = 100;
    int shmKey = 1234;
    int iRet = 0;

    char *ptr = NULL;

    printf("server to create shared memory\n");

    shmid = shmget(shmKey, shmSize, IPC_CREAT | 0777);
    printf("shared memory created successfully\n");

    ptr = shmat(shmid, NULL, 0);
    if (ptr != NULL)
    {
        printf("shared memnory attached successfully\n");
    }

    *ptr = 'H';
    ptr++;

    *ptr = 'E';
    ptr++;

    *ptr = 'L';
    ptr++;

    *ptr = 'L';
    ptr++;

    *ptr = 'O';
    ptr++;

    printf("Data written successfully\n");
    iRet = shmdt(ptr);
    if (iRet == -1)
    {
        printf("failed to detached\n");
    }

    return 0;
}

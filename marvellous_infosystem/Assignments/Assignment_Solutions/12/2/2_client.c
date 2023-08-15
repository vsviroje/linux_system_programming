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
// client
int main()
{
    int shmid = 0;
    int shmSize = 100;
    int shmKey = 1234;
    int iRet = 0;

    char *ptr = NULL;
    char *startPtr = NULL;

    printf("client to attached shared memory\n");

    shmid = shmget(shmKey, shmSize, 0777);

    ptr = shmat(shmid, NULL, 0);
    if (ptr != NULL)
    {
        printf("shared memnory attached successfully\n");
    }
    startPtr = ptr;
    printf("Data from shared memory:\n");

    while (ptr != NULL && *ptr != '\0')
    {
        printf("%c", *ptr);
        ptr++;
    }

    printf("\nData reading done.\n");

    iRet = shmdt(startPtr);
    if (iRet == -1)
    {
        printf("failed to detached\n");
    }

    return 0;
}

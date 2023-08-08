#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

#define SHMSZ 30

int main()
{
    key_t key;
    int shmid;
    char *shm, *s;

    printf("Demo client shared memory\n");
    key = ftok(".", 'a');
    shmid = shmget(key, SHMSZ, IPC_CREAT | 0666);
    shm = shmat(shmid, NULL, 0);

    for (s = shm; *s != '\0'; s++)
    {
        printf("%c", *s);
    }

    printf("\ndata read\n");

    *shm = '*';

    exit(0);
}

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define SHMSZ 30

int main()
{
    char c;
    int shmid;
    char *shm, *s;

    printf("Demo server shared memory\n");
    key_t key = ftok(".", 'a');
    shmid = shmget(key, SHMSZ, IPC_CREAT | 0666);
    shm = shmat(shmid, NULL, 0);

    s = shm;
    for (c = 'a'; c <= 'z'; c++)
    {
        *s = c;
        s++;
    }

    printf("data written\n");

    *s = '\0';

    while (*shm != '*')
    {
        sleep(1);
    }

    printf("data fetched by client\n");

    exit(0);
}

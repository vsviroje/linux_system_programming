#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/shm.h>
#include <sys/wait.h>

// Shared memory example
// server
int main()
{
    int ret = 0;
    int cpid = 0;
    int exit_status = 0;

    ret = fork();

    if (ret == 0) // server
    {
        execl("./server", "NULL", NULL);
    }
    else
    {
        printf("Server process started\n");
    }

    ret = fork();

    if (ret == 0) // client
    {
        execl("./client", "NULL", NULL);
    }
    else
    {
        printf("Client process started\n");
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int ret = 0;
    int cpid = 0;
    int exit_status = 0;

    ret = fork();

    if (ret == 0) // child
    {
        execl("./childProcess1", "NULL", NULL);
    }
    else // parent
    {
        printf("Current PID:%d\n", getpid());
    }

    return 0;
}

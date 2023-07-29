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
        execl("./childProcess1", "demo.txt", NULL);
    }
    else // parent
    {
        printf("Current PID:%d\n", getpid());
        cpid = wait(&exit_status);
        printf("Child PID:%d with exit status:%d\n", cpid, exit_status);
    }

    ret = fork();

    if (ret == 0) // child
    {
        execl("./childProcess1", "hello.txt", NULL);
    }
    else // parent
    {
        printf("Current PID:%d\n", getpid());
        cpid = wait(&exit_status);
        printf("Child PID:%d with exit status:%d\n", cpid, exit_status);
    }

    return 0;
}

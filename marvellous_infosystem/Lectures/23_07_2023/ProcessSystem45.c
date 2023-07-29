#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int ret = 0;

    ret = fork();
    if (ret == 0)
    {
        printf("New child process is running\n");
        printf("PID of new child process:%d\n", getpid());
        printf("PPID of Parent process ie current process:%d\n", getppid());
    }
    else if (ret > 0)
    {
        printf("Current process is running\n");
        printf("PID of New Child process:%d\n", ret);
        printf("PID of Current process:%d\n", getpid());
        printf("PPID of Parent process ie bash/terminal:%d\n", getppid());
    }
    else if (ret == -1)
    {
        printf("failed to create child process.\n");
    }

    return 0;
}
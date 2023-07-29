#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int ret = 0;

    printf("childProcess1\n");

    ret = fork();

    if (ret == 0) // child
    {
        execl("./childProcess2", "NULL", NULL);
    }
    else // parent
    {
        printf("childProcess1 PID:%d\n", getpid());
    }

    return 0;
}

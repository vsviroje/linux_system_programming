#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int ret = 0;
    ret = fork();

    if (ret == 0) // child
    {
        execl("./childProcess", "NULL", NULL);
    }
    else // parent
    {
        printf("Current PID:%d\n", getpid());
        sleep(2);
    }

    return 0;
}

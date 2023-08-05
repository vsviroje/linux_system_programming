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
        while(1){} //so will get same current pid
    }

    return 0;
}

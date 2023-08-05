#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

// MultiProcessing demonstration
int main()
{
    int ret1 = 0;
    int ret2 = 0;
    int cPid1 = 0, cPid2 = 0;
    int status1 = 0, status2 = 0;

    ret1 = fork();

    if (ret1 == 0) // child
    {
        execl("./Process1", "NULL", NULL);
    }

    wait(&status1);

    ret2 = fork();

    if (ret2 == 0) // child
    {
        execl("./Process2", "NULL", NULL);
    }

    wait(&status2);

    return 0;
}
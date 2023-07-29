#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int ret1 = 0;
    int ret2 = 0;

    int cpid1 = 0;
    int cpid2 = 0;

    int exit_status1 = 0;
    int exit_status2 = 0;
    
    printf("Current PID:%d\n", getpid());

    ret1 = fork();

    if (ret1 == 0) // child
    {
        execl("./childProcess1", "NULL", NULL);
    }
    else // parent
    {
        cpid1 = wait(&exit_status1);
        printf("Child PID:%d with exit status:%d\n", cpid1, exit_status1);
    }

    ret2 = fork();

    if (ret2 == 0) // child
    {
        execl("./childProcess1", "NULL", NULL);
    }
    else // parent
    {
        cpid2 = wait(&exit_status2);
        printf("Child PID:%d with exit status:%d\n", cpid2, exit_status2);
    }

    return 0;
}

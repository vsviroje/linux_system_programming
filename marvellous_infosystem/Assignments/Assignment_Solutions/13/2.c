#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void sighup();
void sigint();
void sigquit();

int main()
{
    int pid;
    if ((pid = fork()) < 0)
    {
        exit(1);
    }

    if (pid == 0)
    {
        signal(SIGHUP, sighup);
        signal(SIGINT, sigint);
        signal(SIGQUIT, sigquit);
        for (;;)
            ;
    }
    else
    {
        printf("Parent:sending SIGHUP\n");
        kill(pid, SIGHUP);
        sleep(3);

        printf("Parent:sending SIGINT\n");
        kill(pid, SIGINT);
        sleep(3);

        printf("Parent:sending SIGQUIT\n");
        kill(pid, SIGQUIT);
        sleep(3);
    }

    return 0;
}

void sighup()
{
    printf("child:received SIGHUP\n");
}
void sigint()
{
    printf("child:received SIGINT\n");
}
void sigquit()
{
    printf("child:received SIGQUIT\n");
    exit(0);
}

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void sig_handler_child(int);
void sig_handler_parent(int);

int childPID;

int main()
{
    int ret = 0;
    ret = fork();
    if (ret == 0) // child
    {
        signal(SIGINT, sig_handler_child);
        signal(SIGQUIT, sig_handler_child);
        for (;;)
            ;
    }
    else if (ret > 0) // parent
    {
        signal(SIGINT, sig_handler_parent);
        signal(SIGQUIT, sig_handler_parent);
        sleep(2); // child gets time to register signal handler
        kill(ret, SIGINT);
        childPID = ret;
        for (;;)
            ;
    }

    return 0;
}

void sig_handler_child(int sigNum)
{
    if (sigNum == SIGINT)
    {
        printf("child:received SIGINT\n");
        kill(getppid(), SIGINT);
    }
    else if (sigNum == SIGQUIT)
    {
        printf("child:received SIGQUIT\n");
        kill(getppid(), SIGQUIT);
        exit(0);
    }
}

void sig_handler_parent(int sigNum)
{
    if (sigNum == SIGINT)
    {
        printf("parent:received SIGINT\n");
        kill(childPID, SIGQUIT);
    }
    else if (sigNum == SIGQUIT)
    {
        printf("parent:received SIGQUIT\n");
        exit(0);
    }
}
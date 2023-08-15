#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void sig_handler(int);

int main()
{
    //ps -ef
    signal(SIGUSR1, sig_handler); // kill -USR1 PID

    for (;;)
        ;

    return 0;
}

void sig_handler(int sigNum)
{
    if (sigNum == SIGUSR1)
    {
        printf("child:received SIGUSR1\n");
        exit(0);
    }
    else
    {
        printf("Unknown signal\n");
    }
}
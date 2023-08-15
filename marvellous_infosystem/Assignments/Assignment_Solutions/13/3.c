#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void sig_handler(int);

int main()
{

    signal(SIGINT, sig_handler);  // ctrl+c
    signal(SIGQUIT, sig_handler); //ctrl+\

    for (;;)
        ;

    return 0;
}

void sig_handler(int sigNum)
{
    if (sigNum == SIGINT)
    {
        printf("child:received SIGINT\n");
    }
    else if (sigNum == SIGQUIT)
    {
        printf("child:received SIGQUIT\n");
        exit(0);
    }
    else
    {
        printf("Unknown signal\n");
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{

    printf("inside child proccess PPID:%d and PID:%d\n",getppid(),getpid());

    return 0;
}

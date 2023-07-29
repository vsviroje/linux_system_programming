#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int ret = 0;
    ret = fork();
    printf("ret:%d|PID:%d\n", ret, getpid());
    return 0;
}
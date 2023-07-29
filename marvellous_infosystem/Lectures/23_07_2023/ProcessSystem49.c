#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int No = 10;
//Data section copy

void fun(int ret)
{
    No++;
    printf("ret:%d|PID:%d|No value:%d\n", ret, getpid(),No);
}

int main()
{
    int ret = 0;
    ret = fork();
    if (ret == 0)
    {
        fun(ret);
    }
    else
    {
        No++;
        fun(ret);
    }
    return 0;
}
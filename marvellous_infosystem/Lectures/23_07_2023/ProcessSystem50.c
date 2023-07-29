#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//stack section copy
void fun(int ret)
{
    int No = 10;
    No++;
    printf("ret:%d|PID:%d|No value:%d\n", ret, getpid(), No);
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
        fun(ret);
    }
    return 0;
}
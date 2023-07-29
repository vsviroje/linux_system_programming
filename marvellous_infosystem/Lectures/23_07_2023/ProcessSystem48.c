#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//Text section copy
void fun(int ret)
{
    printf("ret:%d|PID:%d\n", ret, getpid());
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
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int ret = 0;
   
    ret = fork();
    if (ret == 0)
    {
        printf("running child process.\n");
    }
    else
    {
        printf("Parent process is running and child process pID:%d\n", ret);
    }

    return 0;
}
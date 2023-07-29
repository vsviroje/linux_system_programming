#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    printf("Jay Jinendra..!!!\n");
    printf("PID:%d\n", getpid());

    return 0;
}

/*
gcc ProcessSystem51.c  -o childProcess
*/
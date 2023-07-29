#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
    printf("PID:%d\n", getpid());
    printf("%s:%s:%s\n", argv[0],argv[1],argv[2]);

    return 0;
}

/*
gcc ProcessSystem51.c  -o childProcess
*/
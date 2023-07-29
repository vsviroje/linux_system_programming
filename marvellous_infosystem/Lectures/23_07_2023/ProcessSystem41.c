#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int pID = 0;
    pID = getpid();
    printf("PID of running process:%d\n", pID);
    return 0;
}
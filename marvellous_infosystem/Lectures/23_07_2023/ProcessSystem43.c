#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int pID = 0;
    int pPID = 0;
    pID = getpid();
    pPID = getppid();
    
    printf("PID of running process:%d\n", pID);
    printf("PPID of running process:%d\n", pPID);
  
    return 0;
}
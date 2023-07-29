#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_PROC_COUNT 3

int main(int argc, char *argv[])
{
    int ret = 0;
    char strNum[10];

    int processCount = atoi(argv[0]);

    if (processCount == 0)
    {
        processCount = 1;
    }

    if (processCount <= MAX_PROC_COUNT)
    {
        processCount++;

        ret = fork();
        if (ret == 0) // child
        {
            sprintf(strNum, "%d", processCount);
            execl("./currentProcess", strNum, NULL);
        }
        else // parent
        {
            printf("processCount:%d| Current PID:%d | Parent PID:%d\n", processCount - 1, getpid(), getppid());
        }
    }

    return 0;
}
/*
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/8/3$ gcc 3.c -o currentProcess
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/8/3$ ./currentProcess 
processCount:1| Current PID:19075 | Parent PID:20258
processCount:2| Current PID:19076 | Parent PID:1
processCount:3| Current PID:19077 | Parent PID:1
*/
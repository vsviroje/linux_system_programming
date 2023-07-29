#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int ret = 0;
    printf("Process 1\n");

    ret = fork();

    if (ret == 0) // child
    {
        execl("./childProcess1", "NULL", NULL);
    }
    else // parent
    {
        printf("Current PID:%d\n", getpid());
    }

    return 0;
}

/*
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/8/2$ gcc 2_childProcess2.c -o childProcess2
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/8/2$ gcc 2_childProcess1.c -o childProcess1
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/8/2$ gcc 2_currentProcess.c 
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/8/2$ ./a.out 
Process 1
Current PID:18946
childProcess1
childProcess1 PID:18947
childProcess2
*/
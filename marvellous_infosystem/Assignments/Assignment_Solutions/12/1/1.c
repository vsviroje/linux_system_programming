#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int ret = 0;
    int cpid = 0;
    int exit_status = 0;

    ret = fork();

    if (ret == 0) // child
    {
        execl("./childProcess1", "NULL", NULL);
    }
    else // parent
    {
        printf("Current PID:%d\n", getpid());
        cpid = wait(&exit_status);
        printf("Child PID:%d with exit status:%d\n", cpid, exit_status);
    }

    return 0;
}
/*
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/9/1$ gcc childProcess1.c  -o childProcess1
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/9/1$ gcc 1.c 
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/9/1$ ./a.out 
Current PID:23179
Enter Directory Name:
/home/vsviroje
Child PID:23180 with exit status:0
*/
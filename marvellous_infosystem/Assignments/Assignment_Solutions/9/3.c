#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

int main()
{
    int ret = 0;
    ret = getpriority(PRIO_PROCESS, 0);
    printf("current process priority:%d\n", ret);

    return 0;
}
/*
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/9/3$ gcc 3.c 
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/9/3$ ./a.out 
current process priority:0
*/
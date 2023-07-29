#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

int main()
{
    int ret = 0;
    ret = getpriority(PRIO_PROCESS, 0);

    printf("before nice current process priority:%d\n", ret);
    ret = nice(5);
    printf("after nice current process priority:%d\n", ret);

    return 0;
}
/*
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/9$ gcc 4.c 
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/9$ ./a.out 
before nice current process priority:0
after nice current process priority:5
*/
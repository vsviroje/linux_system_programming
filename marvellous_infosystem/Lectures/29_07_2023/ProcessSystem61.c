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

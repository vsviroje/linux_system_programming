#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

int main()
{
    int ret = 0;
    ret = getpriority(PRIO_PROCESS, 0);

    printf("before nice current process priority:%d\n", ret);
    ret = nice(11);
    printf("after nice current process priority:%d\n", ret);

    return 0;
}
/*
       #include <unistd.h>

       int nice(int inc);

nice() adds inc to the nice value for the calling thread.  (A
higher nice value means a lower priority.)

The range of the nice value is +19 (low priority) to -20 (high
priority).  Attempts to set a nice value outside the range are
clamped to the range.
*/
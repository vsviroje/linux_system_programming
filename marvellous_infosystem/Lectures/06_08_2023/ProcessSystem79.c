#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

// Named pipee example
// server
int main()
{
    int fd = 0;
    int iRet = 0;
    char arr[] = "vardhaman viroje";
    char buffer[512];

    fd = mkfifo("Demo", 0777);
    if (fd == -1)
    {
        printf("mkfifo ie name pipe creation failed\n");
    }
    return 0;
}

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
        return -1;
    }

    printf("server is running and writing data into named piped\n");

    fd = open("Demo", O_WRONLY);

    write(fd, arr, strlen(arr));

    close(fd);

    printf("successfully  data writing is done\n");

    return 0;
}

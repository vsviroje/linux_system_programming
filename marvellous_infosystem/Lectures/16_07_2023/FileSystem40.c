#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <sys/dir.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    int fd = 0, ret = 0;
    char arr[200] = {'\0'};
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        printf("unable to open file\n");
        return -1;
    }

    lseek(fd, atoi(argv[2]), 0);

    ret = read(fd, arr, 20);
    write(1, arr, ret);
    close(fd);

    return 0;
}
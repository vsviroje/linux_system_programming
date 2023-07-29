#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char *argv[])
{

    int fd = 0;

    if (argc < 2)
    {
        printf("Invalid argument\n");
        return -1;
    }

    fd = creat(argv[1], 0777);
    if (fd != -1)
    {
        printf("able to open file\n");
    }

    return 0;
}
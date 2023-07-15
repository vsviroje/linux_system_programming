#include <stdio.h>
#include <fcntl.h> //file control...for use by the functions fcntl() and open().
#include <string.h>

int main(int argc, char *argv[])
{

    int fd = 0;
    int mode = 0;

    printf("Usage: executable file OpenMode\n");

    if (argc < 3)
    {
        printf("file name not provided\n");
        return -1;
    }

    if (strcmp(argv[2], "R") == 0)
    {
        mode = O_RDONLY;
    }
    else if (strcmp(argv[2], "W") == 0)
    {
        mode = O_WRONLY;
    }
    else
    {
        printf("Invalid open mode\n");
        return -1;
    }

    fd = open(argv[1], mode);
    if (fd == -1)
    {
        printf("unable to opne file\n");
        return -1;
    }
    else
    {
        printf("able to open file with fd:%d\n", fd);
    }

    return 0;
}

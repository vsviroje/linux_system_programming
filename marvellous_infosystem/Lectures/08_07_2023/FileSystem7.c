#include <stdio.h>
#include <fcntl.h> //file control...for use by the functions fcntl() and open().

int main(int argc, char *argv[])
{

    int fd = 0;

    if (argc < 2)
    {
        printf("file name not provided\n");
        return -1;
    }

    fd = open(argv[1], O_RDONLY);
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

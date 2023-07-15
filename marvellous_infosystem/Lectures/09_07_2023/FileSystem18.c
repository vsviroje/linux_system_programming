#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat sobj;

    if (argc < 2)
    {
        printf("Invalid Num of argument\n");
        return -1;
    }

    stat(argv[1], &sobj);

    if (S_ISREG(sobj.st_mode))
    {
        printf("Its regular file\n");
    }
    else if (S_ISDIR(sobj.st_mode))
    {
        printf("directory\n");
    }
    else if (S_ISLNK(sobj.st_mode))
    {
        printf("symbolic link\n");
    }

    return 0;
}

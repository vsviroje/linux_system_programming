#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    int mode = 0;

    if (argc != 3)
    {
        printf("invalid argument\n");
        return -1;
    }

    if (strcmp(argv[2], "r") == 0)
    {
        mode = R_OK;
    }
    else if (strcmp(argv[2], "w") == 0)
    {
        mode = W_OK;
    }
    else if (strcmp(argv[2], "e") == 0)
    {
        mode = X_OK;
    }
    else
    {
        printf("invalid mode\n");
        return -1;
    }

    if (access(argv[1], mode) < 0)
    {
        printf("Unable to access in specified mode\n");
        return -1;
    }

    printf("Able to access in specified mode\n");

    return 0;
}
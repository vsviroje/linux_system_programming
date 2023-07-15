#include <stdio.h>
#include <fcntl.h>
#include <unistd.h> //Contains POSIX and UNIX system calls
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int fd = 0;

    char *buffer = NULL;
    int ret = 0;
    int NBytes = atoi(argv[2]);

    if (argc < 3)
    {
        printf("Invalid no arguments\n");
        return -1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    buffer = (char *)malloc(NBytes);

    ret = read(fd, buffer, NBytes);
    if (ret == 0)
    {
        printf("Unable to read file\n");
        return -1;
    }

    printf("File data: %s\n", buffer);
    return 0;
}
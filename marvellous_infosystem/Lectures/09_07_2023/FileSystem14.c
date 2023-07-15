#include <stdio.h>
#include <fcntl.h>
#include <unistd.h> //Contains POSIX and UNIX system calls
#include <stdlib.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    int fd = 0;
    int ret = 0;

    char buffer[BLOCKSIZE] = {'\0'};

    if (argc < 2)
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

    while ((ret = read(fd, buffer, sizeof(buffer))) != 0)
    {
        write(1, buffer, ret); //fd = 1 ...stdout
    }
    close(fd);

    printf("\n");
    return 0;
}

/*
close - close a file descriptor
int close(int fd);
DESCRIPTION
        close() closes a file descriptor, so that it no longer refers to
        any file and may be reused. 
*/
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    int fdSrc = 0, fdDst = 0, ret = 0;

    char buffer[BLOCKSIZE] = {'\0'};

    if (argc != 3)
    {
        printf("Invalid no of arguments\n");
        return -1;
    }

    fdSrc = open(argv[1], O_RDONLY);
    if (fdSrc == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    fdDst = creat(argv[2], 0777);
    if (fdSrc == -1)
    {
        printf("Unable to create file\n");
        close(fdSrc);
        return -1;
    }

    while ((ret = read(fdSrc, buffer, sizeof(buffer))) != 0)
    {
        write(fdDst, buffer, ret);
        memset(buffer, 0, sizeof(buffer));
    }

    close(fdSrc);
    close(fdDst);

    return 0;
}
/*
creat — create a new file or rewrite an existing one

int creat(const char *path, mode_t mode);
*/

/*
memset - fill memory with a constant byte

#include <string.h>
void *memset(void s[.n], int c, size_t n);

DESCRIPTION
    The memset() function fills the first n bytes of the memory area
    pointed to by s with the constant byte c.
*/
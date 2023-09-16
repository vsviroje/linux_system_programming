#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd = 0;
    int fdnew = 0;

    fd = open("file.txt", O_RDONLY);

    fdnew = dup(fd);

    printf("FD:%d,NewFD:%d\n", fd, fdnew);
    while (1)
        ;
    return 0;
}
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h> //Contains POSIX and UNIX system calls

int main(int argc, char *argv[])
{
    int fd = 0;
    char buffer[20] = {'\0'};
    int ret = 0;

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

    ret = read(fd, buffer, 10);
    if (ret == 0)
    {
        printf("Unable to read file\n");
        return -1;
    }

    printf("File data: %s\n", buffer);
    return 0;
}
/*
read - read from a file descriptor

ssize_t read(int fd, void buf[.count], size_t count);

DESCRIPTION
    read() attempts to read up to count bytes from file descriptor fd
    into the buffer starting at buf.

    On files that support seeking, the read operation commences at
    the file offset, and the file offset is incremented by the number
    of bytes read.  If the file offset is at or past the end of file,
    no bytes are read, and read() returns zero.
*/
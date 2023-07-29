#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <sys/dir.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    int fd1 = 0, fd2 = 0, ret = 0;
    struct stat s1obj, s2obj;

    char buffer1[BLOCKSIZE] = {'\0'};
    char buffer2[BLOCKSIZE] = {'\0'};

    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_RDONLY);

    if (fd1 == -1 || fd2 == -1)
    {
        printf("failed to open file\n");
        return -1;
    }

    fstat(fd1, &s1obj);
    fstat(fd2, &s2obj);

    if (s1obj.st_size != s2obj.st_size)
    {
        close(fd1);
        close(fd2);
        printf("Files sizes are not equals\n");
        return -1;
    }

    while ((ret = read(fd1, buffer1, sizeof(buffer1))) != 0)
    {
        ret = read(fd2, buffer2, sizeof(buffer2));

        if (memcmp(buffer1, buffer2, ret))
        {
            close(fd1);
            close(fd2);
            printf("Files are not equals\n");
            return -1;
        }
    }

    printf("Files are equals\n");

    close(fd1);
    close(fd2);
    return 0;
}
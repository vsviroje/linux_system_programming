#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{

    char Fname[20];
    int fd = 0;
    int offset = 0;
    int ret = 0;
    char buffer[BLOCKSIZE] = {'\0'};
    struct stat sobj;

    printf("Enter file name to open:\n");
    scanf("%s", Fname);

    fd = open(Fname, O_RDWR);
    if (fd == -1)
    {
        printf("unable to opne file\n");
        return -1;
    }

    fstat(fd, &sobj);

    if (sobj.st_size < BLOCKSIZE)
    {
        ret = lseek(fd, (BLOCKSIZE - sobj.st_size) - 1, SEEK_END);
        if (ret == -1)
        {
            printf("lseek failed\n");
            return -1;
        }

        if (write(fd, "", 1) < 0)
        {
            printf("lseek failed\n");
            return -1;
        }
    }
    else if (sobj.st_size > BLOCKSIZE)
    {
        ret = lseek(fd, BLOCKSIZE, SEEK_SET);
        if (ret == -1)
        {
            printf("lseek failed\n");
            return -1;
        }

        ret = ftruncate(fd, BLOCKSIZE);
        if (ret == -1)
        {
            printf("ftruncate failed\n");
            return -1;
        }
    }

    close(fd);

    return 0;
}

/*
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/6$ gcc 6.c
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/6$ ./a.out
Enter file name to open:
temp2
*/
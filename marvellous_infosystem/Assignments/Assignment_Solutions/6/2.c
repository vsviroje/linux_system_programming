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

    printf("Enter file name to open:\n");
    scanf("%s", Fname);

    fd = open(Fname, O_RDWR);
    if (fd == -1)
    {
        printf("unable to opne file\n");
        return -1;
    }

    ret = lseek(fd, BLOCKSIZE-1, SEEK_END);
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

    close(fd);

    return 0;
}

/*
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/6$ gcc 2.c
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/6$ ./a.out 
Enter file name to open:
temp2
*/
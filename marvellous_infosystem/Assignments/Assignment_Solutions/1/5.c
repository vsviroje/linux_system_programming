#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    int byteCountFinalizer(int *nBytes);
    int fd = 0;
    int ret = 0;
    int nBytes = 0;

    char buffer[BLOCKSIZE] = {'\0'};

    char fName[20];

    printf("File name:\n");
    scanf("%s", fName);

    printf("Num of Bytes:\n");
    scanf("%d", &nBytes);

    fd = open(fName, O_RDONLY);
    if (fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    while ((ret = read(fd, buffer, byteCountFinalizer(&nBytes))) != 0)
    {
        write(1, buffer, ret);
    }
    close(fd);

    printf("\n");
    return 0;
}

int byteCountFinalizer(int *nBytes)
{
    int zero = 0;
    int bSize = BLOCKSIZE;

    if (nBytes == NULL || *nBytes == 0)
    {
        return zero;
    }

    *nBytes = *nBytes - BLOCKSIZE;

    if (*nBytes < 0)
    {
        bSize = -*nBytes;
        *nBytes = zero;
    }
    return bSize;
}

/*
[BLOCKSIZE:10]

vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/1$ gcc 5.c
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/1$ ./a.out 
File name:
5.c
Num of Bytes:
35
#include <stdio.h>
#include <fcntl.
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

#define BLOCKSIZE 1024
#pragma pack(1)
struct FileInfo
{
    char FileName[20];
    int FileSize;
};
int main(int argc, char *argv[])
{
    int byteCountFinalizer(int *nBytes);

    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;
    char buffer[BLOCKSIZE] = {'\0'};

    char dirName[200];
    char fileName[200];

    char filePath[500];
    int fd = 0;
    int ret = 0;
    int fdOut = 0;
    int srcFileSize = 0;
    int tempFileSize = 0;
    int fileInfoStructSize = 0;

    struct FileInfo fileInfo;

    printf("Enter file name:\n");
    scanf("%s", fileName);

    fd = open(fileName, O_RDONLY);
    if (fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    fstat(fd, &sobj);
    srcFileSize = sobj.st_size;

    while (srcFileSize > 0)
    {

        read(fd, &fileInfo, sizeof(fileInfo));

        tempFileSize = fileInfo.FileSize;
        fileInfoStructSize = sizeof(fileInfo);

        if (fileInfo.FileSize > 10)
        {
            printf("FileName:%s\n", fileInfo.FileName);
        }

        while ((ret = read(fd, buffer, byteCountFinalizer(&fileInfo.FileSize))) != 0)
        {
        }

        srcFileSize -= (fileInfoStructSize + tempFileSize);
        memset(&fileInfo, 0, sizeof(fileInfo));
    }

    if (srcFileSize > 0)
    {
        printf("Failed to create files\n");
    }
    else if (srcFileSize == 0)
    {
        printf("Successfully all files are traversed\n");
    }

    close(fd);

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

    if (*nBytes < BLOCKSIZE)
    {
        bSize = *nBytes;
        *nBytes = zero;
        return bSize;
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
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/6$ gcc 1.c 
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/6$ ./a.out 
Enter file name:
../5/AllFileData.txt
FileName:5.c
FileName:3.c
FileName:4.c
FileName:a.out
FileName:2.c
FileName:1.c
Successfully all files are traversed
*/
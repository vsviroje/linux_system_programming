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

    printf("Directory name to push all file:\n");
    scanf("%s", dirName);

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
        printf("srcFileSize:%d\n", srcFileSize);

        read(fd, &fileInfo, sizeof(fileInfo));
        sprintf(filePath, "%s/%s", dirName, fileInfo.FileName);

        tempFileSize = fileInfo.FileSize;
        fileInfoStructSize = sizeof(fileInfo);

        fdOut = creat(filePath, S_IRWXU);
        if (fdOut == -1)
        {
            printf("filePath:%s\n", filePath);
            printf("Unable to create file\n");
            break;
        }

        printf("\nFileName:%s\n", fileInfo.FileName);
        printf("FileSize:%d\n", fileInfo.FileSize);

        while ((ret = read(fd, buffer, byteCountFinalizer(&fileInfo.FileSize))) != 0)
        {
            write(fdOut, buffer, ret);
            memset(buffer, 0, sizeof(buffer));
        }

        close(fdOut);

        srcFileSize -= (fileInfoStructSize + tempFileSize);
        memset(&fileInfo, 0, sizeof(fileInfo));
    }

    if (srcFileSize > 0)
    {
        printf("Failed to create files\n");
    }
    else if (srcFileSize == 0)
    {
        printf("Successfully all files are created in specified dir\n");
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
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/5$ gcc 5.c 
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/5$ ./a.out 
Enter file name:
AllFileData.txt
Directory name to push all file:
temp
srcFileSize:22850

FileName:5.c
FileSize:2878
srcFileSize:19948

FileName:3.c
FileSize:2013
srcFileSize:17911

FileName:4.c
FileSize:3090
srcFileSize:14797

FileName:a.out
FileSize:13184
srcFileSize:1589

FileName:2.c
FileSize:980
srcFileSize:585

FileName:1.c
FileSize:561
Successfully all files are created in specified dir
 */
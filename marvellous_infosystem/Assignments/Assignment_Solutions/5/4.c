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
    char filePath[500];
    int fd = 0;
    int ret = 0;
    int fdOut = 0;

    char OutFileName[] = "AllFileData.txt";
    char FileSeparator[] = "\n--EOF--\n"; // eod of file
    char FileNameSeparator[100];

    struct FileInfo fileInfo;

    printf("Directory name:\n");
    scanf("%s", dirName);

    dp = opendir(dirName);
    if (dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    fdOut = creat(OutFileName, S_IRWXU);
    if (fdOut == -1)
    {
        printf("Unable to create file\n");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        sprintf(filePath, "%s/%s", dirName, entry->d_name);
        stat(filePath, &sobj);

        printf("filePath:%s\n", filePath);

        if (sobj.st_size > 0 && S_ISREG(sobj.st_mode))
        {
            if (!strcmp(OutFileName, entry->d_name))
            {
                printf("Continued:%s\n", filePath);
                continue;
            }

            fd = open(filePath, O_RDONLY);
            if (fd == -1)
            {
                printf("Unable to open file\n");
                close(fdOut);
                closedir(dp);
                return -1;
            }

            strcpy(fileInfo.FileName, entry->d_name);
            fileInfo.FileSize = sobj.st_size;

            write(fdOut, &fileInfo, sizeof(fileInfo));
            while ((ret = read(fd, buffer, sizeof(buffer))) != 0)
            {
                write(fdOut, buffer, ret);
                memset(buffer, 0, sizeof(buffer));
            }

            // printf("file added:%s\n", entry->d_name);
            close(fd);
        }
    }

    close(fdOut);
    closedir(dp);

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
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/4$ gcc 4.c
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/4$ ./a.out
Directory name:
.
filePath:./5.c
filePath:./3.c
filePath:./4.c
filePath:./a.out
filePath:./temp2_dir
filePath:./..
filePath:./2.c
filePath:./temp1_dir
filePath:./.
filePath:./Demo.txt
Continued:./Demo.txt
filePath:./1.c
 */
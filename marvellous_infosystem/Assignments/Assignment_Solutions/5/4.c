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
    // int FileSize;
};
int main(int argc, char *argv[])
{
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
            
            write(fdOut, &fileInfo, sizeof(fileInfo));
            write(fdOut, "\n", strlen(FileNameSeparator));
            while ((ret = read(fd, buffer, sizeof(buffer))) != 0)
            {
                write(fdOut, buffer, ret);
                // printf("\nbuffer:%s", buffer);
                memset(buffer, 0, sizeof(buffer));
            }
            write(fdOut, FileSeparator, strlen(FileSeparator));

            close(fd);
        }
    }

    close(fdOut);
    closedir(dp);

    fd = open(OutFileName, O_RDONLY);
    if (fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    while ((ret = read(fd, buffer, sizeof(buffer))) != 0)
    {
        printf("%s", buffer);
    }
    close(fd);

    return 0;
}
/*
 */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h> //format of directory entries

#pragma pack(1)
struct FileInfo
{
    char FileName[20];
    int FileSize;
};

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char dirName[20];
    char filePath[500];
    struct stat sobj;
    char fileName[100];

    struct FileInfo fobj;
    int fd = 0;

    printf("Enter Directory Name:\n");
    scanf("%s", dirName);

    dp = opendir(dirName);
    if (dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    fd = creat("FileCombine.txt", 0777);

    while ((entry = readdir(dp)) != NULL)
    {
        sprintf(filePath, "%s/%s", dirName, entry->d_name);
        stat(filePath, &sobj);

        if (S_ISREG(sobj.st_mode))
        {
            fobj.FileSize=sobj.st_size;
            strcpy(fobj.FileName,entry->d_name);
            write(fd,&fobj,sizeof(fobj));
        }
    }

    close(fd);
    closedir(dp);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h> //format of directory entries

#define BLOCKSIZE 1024

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
    char buffer[BLOCKSIZE] = {'\0'};

    struct FileInfo fobj;
    int fd = 0;
    int ret = 0;

    printf("Enter Directory Name:\n");
    scanf("%s", dirName);

    dp = opendir(dirName);
    if (dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    fd = creat("FileInfoCombine.txt", 0777);

    while ((entry = readdir(dp)) != NULL)
    {
        sprintf(filePath, "%s/%s", dirName, entry->d_name);
        stat(filePath, &sobj);

        if (S_ISREG(sobj.st_mode))
        {
            fobj.FileSize = sobj.st_size;
            strcpy(fobj.FileName, entry->d_name);
            write(fd, &fobj, sizeof(fobj));
        }
    }

    close(fd);
    closedir(dp);

    fd = open("FileInfoCombine.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    while ((ret = read(fd, &fobj, sizeof(fobj))) != 0)
    {
        printf("FileName:%s\t", fobj.FileName);
        printf("FileSize:%d\n", fobj.FileSize);
    }
    close(fd);

    return 0;
}
/*
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/5$ gcc 3.c 
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/5$ ./a.out 
Enter Directory Name:
.
FileName:3.c    FileSize:1999
FileName:a.out  FileSize:13056
FileName:2.c    FileSize:980
FileName:FileInfoCombine.txt    FileSize:72
FileName:temp1  FileSize:32
FileName:1.c    FileSize:561
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h> //format of directory entries

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char dirName[20];
    char fileName[50];
    struct stat sobj;

    printf("Enter Directory Name:\n");
    scanf("%s", dirName);

    dp = opendir(dirName);
    if (dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        sprintf(fileName, "%s/%s", dirName, entry->d_name);
        stat(fileName, &sobj);

        printf("File Name:%s\t", fileName);
        printf("File size:%ld\n", sobj.st_size);
    }

    closedir(dp);
    return 0;
}
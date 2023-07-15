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
    char filePath[500];
    struct stat sobj;
    char fileName[100];
    int sizeMax = 0;

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
        sprintf(filePath, "%s/%s", dirName, entry->d_name);
        stat(filePath, &sobj);

        if (S_ISREG(sobj.st_mode))
        {
            if (sobj.st_size == 0)
            {
                remove(entry->d_name);
                printf("File Name with Zero size|Deleted:%s\n", entry->d_name);
            }
        }
    }

    closedir(dp);
    return 0;
}
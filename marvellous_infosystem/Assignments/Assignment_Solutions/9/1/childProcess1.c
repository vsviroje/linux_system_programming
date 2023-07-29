#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
int main()
{
    int sid = 0;
    int i = 0;
    int fd = 0;
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char dirName[20];
    char filePath[500];
    struct stat sobj;

    char buffer[300] = {'\0'};

    printf("Enter Directory Name:\n");
    scanf("%s", dirName);

    dp = opendir(dirName);
    if (dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    fd = creat("demo.txt", 0777);
    if (fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        sprintf(filePath, "%s/%s", dirName, entry->d_name);
        stat(filePath, &sobj);
        sprintf(buffer, "%s\n", entry->d_name);
        write(fd, buffer, strlen(buffer));
    }

    close(fd);
    closedir(dp);

    return 0;
}

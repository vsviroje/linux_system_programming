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
        printf("%7lu:%20s\n", entry->d_ino, entry->d_name);
    }

    closedir(dp);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <sys/dir.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char filePath[500] = {'\0'};

    dp = opendir(argv[1]);
    if (dp == NULL)
    {
        printf("Unable to open dir\n");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL)
    {

        if ((strcmp(argv[2], entry->d_name)) == 0)
        {
            sprintf(filePath, "%s/%s", argv[1], argv[2]);
            if (remove(filePath))
            {
                printf("File is removed\n");
            }
            break;
        }
    }

    if (entry == NULL)
    {
        printf("File is not present\n");
    }

    closedir(dp);
    return 0;
}
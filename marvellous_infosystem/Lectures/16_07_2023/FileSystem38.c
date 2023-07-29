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
    char oldName[300] = {'\0'};
    char newName[300] = {'\0'};
    int counter=1;

    dp = opendir(argv[1]);
    if (dp == NULL)
    {
        printf("unable to opendir\n");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        
        sprintf(oldName, "%s/%s", argv[1], entry->d_name);
        sprintf(newName, "%s/%d.txt", argv[1], counter);//. .. will not rename/move
        counter++;

        rename(oldName, newName);
    }

    closedir(dp);
    return 0;
}
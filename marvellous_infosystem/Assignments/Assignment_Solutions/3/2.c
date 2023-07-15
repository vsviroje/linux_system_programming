#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;

    char dirName[200];
    char fName[20];
    int isFound = 0;

    printf("Directory name:\n");
    scanf("%s", dirName);

    printf("File name:\n");
    scanf("%s", fName);

    dp = opendir(dirName);
    if (dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        if (!strcmp(fName, entry->d_name))
        {
            printf("File is present.\n");
            isFound = 1;
            break;
        }
    }

    if (isFound == 0)
    {
        printf("File is not present.\n");
    }

    closedir(dp);

    return 0;
}
/*
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/3$ gcc 2.c 
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/3$ ./a.out 
Directory name:
.
File name:
out_temp
File is present.
*/
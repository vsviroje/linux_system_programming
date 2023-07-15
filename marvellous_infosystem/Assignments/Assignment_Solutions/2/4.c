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
    struct stat sobj;

    char directoryName[500];
    char fPath[500];
    char fType[20];

    printf("Directory name:\n");
    scanf("%s", directoryName);

    dp = opendir(directoryName);
    if (dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }
    printf("----------------------------------------------------------\n");
    printf("File Name:\tFile Type\n");
    printf("----------------------------------------------------------\n");

    while ((entry = readdir(dp)) != NULL)
    {
        sprintf(fPath, "%s/%s", directoryName, entry->d_name);
        stat(fPath, &sobj);

        if (S_ISREG(sobj.st_mode))
        {
            strcpy(fType, "Regular");
        }
        else if (S_ISDIR(sobj.st_mode))
        {
            strcpy(fType, "Directory");
        }
        else if (S_ISLNK(sobj.st_mode))
        {
            strcpy(fType, "Symbolic Link");
        }
        else
        {
            strcpy(fType, "Unknown");
        }

        printf("%s\t:%s\n", entry->d_name,fType);
    }

    printf("----------------------------------------------------------\n");
    closedir(dp);

    return 0;
}
/*
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/2$ gcc 4.c 
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/2$ ./a.out
Directory name:
..
----------------------------------------------------------
File Name:      File Type
----------------------------------------------------------
..      :Directory
2       :Directory
.       :Directory
Command :Regular
.vscode :Directory
1       :Directory
*/
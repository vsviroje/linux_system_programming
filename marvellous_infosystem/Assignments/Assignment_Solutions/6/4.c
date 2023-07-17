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
            if (sobj.st_size > 100)
            {
                remove(filePath);
                printf("File Name with 100 bSize|Deleted:%s\n", entry->d_name);
            }
        }
    }

    closedir(dp);
    return 0;
}
/*
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/6$ gcc 4.c 
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/6$ ./a.out 
Enter Directory Name:
tempDir
File Name with 100 bSize|Deleted:3.c
File Name with 100 bSize|Deleted:4.c
File Name with 100 bSize|Deleted:a.out
File Name with 100 bSize|Deleted:1.c
*/
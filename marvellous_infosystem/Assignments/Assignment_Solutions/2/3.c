#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;

    char fName[20];

    printf("Directory name:\n");
    scanf("%s", fName);

    dp = opendir(fName);
    if (dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }
    printf("----------------------------------------------------------\n");
    printf("File Name:\n");
    printf("----------------------------------------------------------\n");

    while ((entry = readdir(dp)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }

    printf("----------------------------------------------------------\n");
    closedir(dp);

    return 0;
}
/*
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/2$ gcc 3.c 
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/2$ ./a.out
Directory name:
.
----------------------------------------------------------
File Name:
----------------------------------------------------------
3.c
temp_2
a.out
..
2.c
.
temp_1
1.c
----------------------------------------------------------
*/
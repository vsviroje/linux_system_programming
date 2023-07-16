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
    char dirName[50];
    int ret = 0;

    printf("Enter Directory Name:\n");
    scanf("%s", dirName);

    ret = mkdir(dirName, 0777);
    if (ret == -1)
    {
        printf("Unable to make dir\n");
        return -1;
    }
    closedir(dp);
    return 0;
}
/*
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/4$ gcc 2.c 
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/4$ ./a.out 
Enter Directory Name:
temp2_dir
*/
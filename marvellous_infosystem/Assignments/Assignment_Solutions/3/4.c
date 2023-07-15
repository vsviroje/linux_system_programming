#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int ret = 0;
    DIR *dp = NULL;
    struct dirent *entry = NULL;

    char srcDirName[200];
    char srcFilePath[500];

    struct stat sobj;

    printf("Directory name:\n");
    scanf("%s", srcDirName);

    dp = opendir(srcDirName);
    if (dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL)
    {

        sprintf(srcFilePath, "%s/%s", srcDirName, entry->d_name);
        stat(srcFilePath, &sobj);

        printf("Path | file:%s | st_size:%ld\n", srcFilePath, sobj.st_size);
        if (sobj.st_size == 0)
        {
            ret = unlink(srcFilePath);
            if (ret == -1)
            {
                printf("Delete operation failed for src:%s\n", srcFilePath);
            }
        }
    }

    return 0;
}
/*
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/3$ gcc 4.c 
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/3$ ./a.out 
Directory name:
temp2_dir
Path | file:temp2_dir/temp_2 | st_size:22
Path | file:temp2_dir/.. | st_size:4096
Path | file:temp2_dir/temp_2 copy | st_size:0
Path | file:temp2_dir/. | st_size:4096
Path | file:temp2_dir/temp_1 | st_size:4216
*/
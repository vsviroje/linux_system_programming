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
    char dstDirName[200];
    char srcFilePath[500];
    char dstFilePath[500];

    int isAllMovedFailed = 0;

    struct stat sobj;

    printf("Src Directory name:\n");
    scanf("%s", srcDirName);

    printf("Dst Directory name:\n");
    scanf("%s", dstDirName);

    dp = opendir(srcDirName);
    if (dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL)
    {

        sprintf(srcFilePath, "%s/%s", srcDirName, entry->d_name);
        sprintf(dstFilePath, "%s/%s", dstDirName, entry->d_name);

        stat(srcFilePath, &sobj);

        printf("Path | src:%s | dst:%s\n", srcFilePath, dstFilePath);
        if (S_ISREG(sobj.st_mode))
        {
            ret = rename(srcFilePath, dstFilePath);
            if (ret == -1)
            {
                printf("Move operation failed for src:%s | dst:%s\n", srcFilePath, dstFilePath);
                isAllMovedFailed = 1;
                break;
            }
        }
    }

    if (isAllMovedFailed == 0)
    {
        printf("Move operation succeeded\n");
    }
    return 0;
}
/*
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/3$ gcc 3.c 
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/3$ ./a.out 
Src Directory name:
temp1_dir
Dst Directory name:
temp2_dir
Path | src:temp1_dir/temp_2 | dst:temp2_dir/temp_2
Path | src:temp1_dir/.. | dst:temp2_dir/..
Path | src:temp1_dir/. | dst:temp2_dir/.
Path | src:temp1_dir/temp_1 | dst:temp2_dir/temp_1
Move operation succeeded
*/
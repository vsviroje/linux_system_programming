#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h> //format of directory entries

int main(int argc, char *argv[])
{
    char dirName[200];
    char fName[200];
    char path[500];
    int fd;

    printf("Enter Directory Name:\n");
    scanf("%s", dirName);

    printf("Enter File Name:\n");
    scanf("%s", fName);

    sprintf(path, "%s/%s", dirName, fName);

    fd = creat(path, 0777);
    if (fd == -1)
    {
        printf("Failed to create the file\n");
        return -1;
    }

    printf("Succeeded to create the file\n");

    close(fd);

    return 0;
}
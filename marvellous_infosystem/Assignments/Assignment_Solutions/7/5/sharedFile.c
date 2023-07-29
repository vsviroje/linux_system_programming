#include "sharedFile.h"

void GetFileInfo(char *fName)
{
    struct stat sobj;
    int fd = 0;

    fd = open(fName, O_RDONLY);
    fstat(fd, &sobj);

    printf("File Name:%s\n", fName);
    printf("File size:%ld\n", sobj.st_size);
    printf("Number of links:%ld\n", sobj.st_nlink);
    printf("Inode number:%ld\n", sobj.st_ino);
    printf("File system number:%ld\n", sobj.st_dev);
    printf("Number of blocks:%ld\n", sobj.st_blocks);

    close(fd);
    return;
}



/*
to generate .c to .o file
gcc -c sharedFile.c -o sharedFile.o

to generate .o to .a file
ar rcs sharedFile.a sharedFile.o
*/
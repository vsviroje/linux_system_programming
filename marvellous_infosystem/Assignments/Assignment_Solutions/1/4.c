#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat sobj;
    int fd = 0;

    char fName[20];

    printf("File name:\n");
    scanf("%s", fName);

    fd = open(fName, O_RDONLY);
    fstat(fd, &sobj);

    printf("File Name:%s\n", fName);
    printf("File size:%ld\n", sobj.st_size);
    printf("Number of links:%ld\n", sobj.st_nlink);
    printf("Inode number:%ld\n", sobj.st_ino);
    printf("File system number:%ld\n", sobj.st_dev);
    printf("Number of blocks:%ld\n", sobj.st_blocks);
    close(fd);

    return 0;
}

/*
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/1$ gcc 4.c 
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/1$ ./a.out 
File name:
4.c
File Name:4.c
File size:617
Number of links:1
Inode number:3941386
File system number:2070
Number of blocks:8
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat sobj;
    int fd = 0;

    if (argc < 2)
    {
        printf("Invalid Num of argument\n");
        return -1;
    }

    fd = open(argv[1], O_RDONLY);
    fstat(fd, &sobj);

    printf("File Name:%s\n", argv[1]);
    printf("File size:%ld\n", sobj.st_size);
    printf("Number of links:%ld\n", sobj.st_nlink);
    printf("Inode number:%ld\n", sobj.st_ino);
    printf("File system number:%ld\n", sobj.st_dev);
    printf("Number of blocks:%ld\n", sobj.st_blocks);

    return 0;
}

/*
stat():system call
#include <sys/stat.h>

int stat(const char *restrict pathname,struct stat *restrict statbuf);
int fstat(int fd, struct stat *statbuf);
int lstat(const char *restrict pathname,struct stat *restrict statbuf);

DESCRIPTION
    These functions return information about a file, in the buffer
    pointed to by statbuf.  No permissions are required on the file
    itself, but—in the case of stat(), fstatat(), and lstat()—execute
    (search) permission is required on all of the directories in
    pathname that lead to the file.

    stat() and fstatat() retrieve information about the file pointed
    to by pathname.

    lstat() is identical to stat(), except that if pathname is a
    symbolic link, then it returns information about the link itself,
    not the file that the link refers to.

    fstat() is identical to stat(), except that the file about which
    information is to be retrieved is specified by the file
    descriptor fd.
*/

/*
The stat structure
    Describes information about a file.
    All of these system calls return a stat structure.
    
*/
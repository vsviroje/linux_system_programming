#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    int fdSrc = 0, fdDst = 0, srcRet = 0, dstRet = 0;

    char srcFbuffer[BLOCKSIZE] = {'\0'};
    char dstFbuffer[BLOCKSIZE] = {'\0'};
    char srcFNane[100] = {'\0'};
    char dstFNane[100] = {'\0'};

    struct stat s1obj;
    struct stat s2obj;

    if (argc < 3)
    {
        printf("Invalid no of arguments|ActualCount:%d\n", argc);
        while (argc > 0)
        {
            argc--;
            printf("Argument%d:%s\n", argc, argv[argc]);
        }
        return -1;
    }

    strcpy(srcFNane, argv[1]);
    strcpy(dstFNane, argv[2]);

    printf("Src:%s||Dst:%s\n", srcFNane, dstFNane);

    fdSrc = open(srcFNane, O_RDONLY);
    if (fdSrc == -1)
    {
        printf("Unable to open Src file\n");
        return -1;
    }

    fdDst = open(dstFNane, O_RDONLY);
    if (fdDst == -1)
    {
        printf("Unable to open dst file\n");
        close(fdSrc);
        return -1;
    }

    fstat(fdSrc, &s1obj);
    fstat(fdDst, &s2obj);

    if (s1obj.st_size != s2obj.st_size)
    {
        close(fdSrc);
        close(fdDst);
        printf("Files are not equals\n");
        return -1;
    }

    while ((srcRet = read(fdSrc, srcFbuffer, sizeof(srcFbuffer))) != 0 && (dstRet = read(fdDst, dstFbuffer, sizeof(dstFbuffer))) != 0)
    {
        if (memcmp(srcFbuffer, dstFbuffer, sizeof(srcFbuffer)))
        {
            close(fdSrc);
            close(fdDst);
            printf("Files are not equals\n");
            return -1;
        }

        memset(srcFbuffer, 0, sizeof(srcFbuffer));
        memset(dstFbuffer, 0, sizeof(dstFbuffer));
    }

    printf("Both Files are equals\n");

    close(fdSrc);
    close(fdDst);

    return 0;
}

/*
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/4$ gcc 3.c 
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/4$ ./a.out 3.c 3.c 
Src:3.c||Dst:3.c
Both Files are equals
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/4$ ./a.out 3.c 2.c 
Src:3.c||Dst:2.c
Files are not equals
*/
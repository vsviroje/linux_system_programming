#include "sharedFile.h"

int isFileSame(char *srcFNane, char *dstFNane)
{
    int fdSrc = 0, fdDst = 0, srcRet = 0, dstRet = 0;

    char srcFbuffer[BLOCKSIZE] = {'\0'};
    char dstFbuffer[BLOCKSIZE] = {'\0'};

    struct stat s1obj;
    struct stat s2obj;

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
to generate .o file
gcc -c -fPIC sharedFile.c

to generate .so file
gcc -shared -o library.so sharedFile.o

display info .so file
nm -g library.so
*/
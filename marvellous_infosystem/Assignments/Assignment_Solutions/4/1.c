#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    int fdSrc = 0, fdDst = 0, ret = 0;

    char buffer[BLOCKSIZE] = {'\0'};
    char srcFNane[100] = {'\0'};
    char dstFNane[100] = {'\0'};

    if (argc < 4)
    {
        printf("Invalid no of arguments|ActualCount:%d\n", argc);
        while (argc > 0)
        {
            argc--;
            printf("Argument%d:%s\n", argc, argv[argc]);
        }
        return -1;
    }

    if (!strcmp(argv[2], "<"))
    {
        strcpy(srcFNane, argv[3]);
        strcpy(dstFNane, argv[1]);
    }
    else if (!strcmp(argv[2], ">"))
    {
        strcpy(srcFNane, argv[1]);
        strcpy(dstFNane, argv[3]);
    }
    else
    {
        printf("Unknown io redirection opt\n");
        return -1;
    }

    printf("Src:%s||Dst:%s\n", srcFNane, dstFNane);

    fdSrc = open(srcFNane, O_RDONLY);
    if (fdSrc == -1)
    {
        printf("Unable to open Src file\n");
        return -1;
    }

    fdDst = open(dstFNane, O_WRONLY | O_APPEND);
    if (fdDst == -1)
    {
        printf("Unable to open dst file\n");
        close(fdSrc);
        return -1;
    }

    while ((ret = read(fdSrc, buffer, sizeof(buffer))) != 0)
    {
        write(fdDst, buffer, ret);
        memset(buffer, 0, sizeof(buffer));
    }

    close(fdSrc);
    close(fdDst);

    return 0;
}

/*
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/4$ ./a.out temp1_dir/temp_1 '>' temp1_dir/temp_2
Src:temp1_dir/temp_1||Dst:temp1_dir/temp_2
*/
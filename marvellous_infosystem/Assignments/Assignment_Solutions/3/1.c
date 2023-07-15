#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    int fdSrc = 0, fdDst = 0, ret = 0;

    char buffer[BLOCKSIZE] = {'\0'};
    char srcFNane[100];
    char dstFNane[30];

    printf("Enter Src File name:\n");
    scanf("%s", srcFNane);

     printf("Enter Dst file Name:\n");
    scanf("%s", dstFNane);

    fdSrc = open(srcFNane, O_RDONLY);
    if (fdSrc == -1)
    {
        printf("Unable to open Src file\n");
        return -1;
    }

    fdDst = creat(dstFNane, 0777);
    if (fdSrc == -1)
    {
        printf("Unable to create file\n");
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
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/3$ gcc 1.c 
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/3$ ./a.out 
Enter Src File name:
../2/temp_1
Enter Dst file Name:
out_temp
*/
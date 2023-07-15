#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{

    int fd = 0;
    int mode = 0;
    char fName[20];
    char fMode[5];

    printf("File name:\n");
    scanf("%s", fName);
    printf("File mode:\n");
    scanf("%s", fMode);

    if (strcmp(fMode, "R") == 0)
    {
        mode = O_RDONLY;
    }
    else if (strcmp(fMode, "W") == 0)
    {
        mode = O_WRONLY;
    }
    else if (strcmp(fMode, "RW") == 0)
    {
        mode = O_RDWR;
    }
    else if (strcmp(fMode, "A") == 0)
    {
        mode = O_APPEND;
    }
    else
    {
        printf("Invalid open mode\n");
        return -1;
    }

    fd = open(fName, mode);
    if (fd == -1)
    {
        printf("unable to opne file\n");
        return -1;
    }
    else
    {
        printf("File with fd:%d\n", fd);
    }
    close(fd);

    return 0;
}

/*
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/1$ gcc 2.c 
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/1$ ./a.out 
File name:
2.c
File mode:
W
File with fd:3
*/
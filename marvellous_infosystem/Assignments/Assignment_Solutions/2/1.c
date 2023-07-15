#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    int fd = 0;
    int ret = 0;

    char buffer[BLOCKSIZE] = {'\0'};

    char fName[20];

    printf("File name:\n");
    scanf("%s", fName);

    fd = open(fName, O_RDONLY);
    if (fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    while ((ret = read(fd, buffer, sizeof(buffer))) != 0)
    {
        write(1, buffer, ret);
    }
    close(fd);

    printf("\n");
    return 0;
}
/*
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/2$ gcc 1.c 
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/2$ ./a.out 
File name:
temp     
Michael Kerrisk is a freelance trainer, writer, and consultant who has been using and programming on UNIX systems since 1987. He is
...
*/
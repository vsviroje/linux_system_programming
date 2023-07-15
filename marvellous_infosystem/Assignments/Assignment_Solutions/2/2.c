#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    int ret = 0;

    char *buffer = "Dummy data\n";

    char fName[20];

    printf("File name:\n");
    scanf("%s", fName);

    fd = open(fName, O_WRONLY | O_APPEND);
    if (fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }
    
    write(fd, buffer, strlen(buffer));

    close(fd);

    printf("\n");
    return 0;
}
/*
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/2$ gcc 2.c 
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/2$ ./a.out
File name:
temp_2

*/
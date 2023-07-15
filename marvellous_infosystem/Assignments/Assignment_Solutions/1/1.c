#include <stdio.h>
#include <fcntl.h> //file control...for use by the functions fcntl() and open().

int main(int argc, char *argv[])
{

    char Fname[20];
    int fd = 0;
    printf("Enter file name to open:\n");
    scanf("%s", Fname);

    fd = open(Fname, O_RDONLY);
    if (fd == -1)
    {
        printf("unable to opne file\n");
        return -1;
    }
    else
    {
        printf("Able to open file with fd:%d\n", fd);
    }
    close(fd);

    return 0;
}

/*
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/1$ gcc 1.c 
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/1$ ./a.out 
Enter file name to open:
1.c
Able to open file with fd:3
*/
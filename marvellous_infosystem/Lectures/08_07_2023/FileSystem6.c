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
        printf("able to open file with fd:%d\n", fd);
    }

    return 0;
}

/*
O_RDONLY
Open for reading only.
O_RDWR
Open for reading and writing.
O_WRONLY
Open for writing only.
O_CREAT
Create file if it does not exist.
*/
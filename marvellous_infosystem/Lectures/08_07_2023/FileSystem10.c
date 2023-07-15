#include <stdio.h>
#include <fcntl.h> //file control...for use by the functions fcntl() and open().
#include <string.h>

int main(int argc, char *argv[])
{

    int fd = 0;

    printf("Usage: executable_name file_name \n");

    if (argc < 2)
    {
        printf("Invalid no of arg\n");
        return -1;
    }

    fd = creat(argv[1], 0777);
    if (fd == -1)
    {
        printf("unable to creat file\n");
        return -1;
    }
    else
    {
        printf("able to create file with fd:%d\n", fd);
    }

    return 0;
}

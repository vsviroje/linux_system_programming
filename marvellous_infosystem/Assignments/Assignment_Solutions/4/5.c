#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{

    char Fname[20];
    int fd = 0;
    int offset = 0;
    int ret = 0;
    char buffer[BLOCKSIZE] = {'\0'};

    printf("Enter file name to open:\n");
    scanf("%s", Fname);
    printf("Enter read offset:\n");
    scanf("%d", &offset);

    fd = open(Fname, O_RDONLY);
    if (fd == -1)
    {
        printf("unable to opne file\n");
        return -1;
    }

    ret = lseek(fd, offset, SEEK_SET);
    if (ret == -1)
    {
        printf("lseek failed\n");
        return -1;
    }

    if ((ret = read(fd, buffer, 20)) != 0)
    {
        write(1, buffer, ret);
        // printf("\nbuffer:%s", buffer);
        memset(buffer, 0, sizeof(buffer));
    }

    close(fd);

    return 0;
}

/*
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/4$ gcc 5.c
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/4$ ./a.out 
Enter file name to open:
temp1_dir/temp_1                                              
Enter read offset:
30
 trainer, writer, an
*/
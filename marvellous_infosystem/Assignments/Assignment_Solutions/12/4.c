#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main(int argc, char *argv[])
{
    struct stat sobj;
    int fd = 0;
    char *mmapAddr = NULL;

    char fName[20] = "demo.txt";
    char buff[2000];

    fd = open(fName, O_RDONLY);
    if (fd < 0)
    {
        printf("failed to open file\n");
        return -1;
    }
    fstat(fd, &sobj);

    mmapAddr = mmap(NULL,
                    sobj.st_size,
                    PROT_READ,
                    MAP_SHARED,
                    fd,
                    0);

    if (mmapAddr == MAP_FAILED)
    {
        printf("failed to mmap\n");
        return -1;
    }

    close(fd);

    write(1, mmapAddr, sobj.st_size);

    munmap(mmapAddr, sobj.st_size);

    return 0;
}

/*

*/
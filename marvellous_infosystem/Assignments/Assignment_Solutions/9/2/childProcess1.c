#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
int main(int argc, char *argv[])
{
    int sid = 0;
    int i = 0;
    int fd1 = 0;
    int fd2 = 0;
    int ret = 0;
    int upper = 0;
    char buffer[500] = {'\0'};

    fd1 = open(argv[0], O_RDONLY);
    if (fd1 == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    while ((ret = read(fd1, buffer, sizeof(buffer))) != 0)
    {
        for (i = 0; buffer[i] != '\0'; i++)
        {
            if (buffer[i] >= 'A' && buffer[i] <= 'Z')
            {
                upper++;
            }
        }
    }

    fd2 = open("count.txt", O_RDWR | O_APPEND | O_CREAT);
    if (fd2 == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    sprintf(buffer, "%s has number of uppercase:%d\n", argv[0], upper);
    write(fd2, buffer, strlen(buffer));

    close(fd1);
    close(fd2);
    return 0;
}
/*

*/
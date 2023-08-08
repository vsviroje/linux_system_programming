#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define MAX_BUF 1024

int main()
{
    int fd;

    char *myfifo = "/tmp/myfifo";
    char buf[MAX_BUF];

    printf("Named pipe client\n");

    fd = open(myfifo, O_RDONLY);

    read(fd, buf, sizeof(buf));
    printf("Data read from named pipe:%s\n", buf);
    close(fd);

    return 0;
}
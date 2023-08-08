#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd;
    
    char *myfifo = "/tmp/myfifo";
    char data[] = "Vardhaman viroje";

    printf("Named pipe server\n");

    mkfifo(myfifo, 0666);
    
    fd = open(myfifo, O_WRONLY);
    
    write(fd, data, strlen(data));
    close(fd);
    
    printf("Data written in named pipe\n");

    return 0;
}
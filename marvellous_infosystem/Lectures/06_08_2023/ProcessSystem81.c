#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

// Named pipee example
// client
int main()
{
    int fd = 0;
    int iRet = 0;
    char buffer[512];

    
    printf("client is ready to recieve data from pipe\n");

    fd = open("Demo", O_RDONLY);
    read(fd, buffer, sizeof(buffer));
    printf("successfully  data reading:%s\n",buffer);
    close(fd);

    return 0;
}

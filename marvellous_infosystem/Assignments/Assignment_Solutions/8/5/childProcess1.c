#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int sid = 0;
    int i = 0;
    int fd = 0;

    char buffer[100] = {'\0'};

    sid = setsid();
    if (sid < 0)
    {
        printf("Failed to create new session\n");
        return -1;
    }

    umask(0);

    fd = creat("temp.txt", 0777);
    if (fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    sprintf(buffer, "Daemon proccess PPID:%d and PID:%d\n", getppid(), getpid());
    write(fd, buffer, strlen(buffer));

    for (i = 0; i < 100; i++)
    {
        sprintf(buffer, "i=%d\n", i);
        write(fd, buffer, strlen(buffer));
        sleep(1);
    }

    close(fd);

    return 0;
}

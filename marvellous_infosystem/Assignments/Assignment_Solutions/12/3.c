#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <string.h>
#include <sys/wait.h>

// Unnamed pipe
int main()
{
    int fd[2];
    int iRet = 0;
    char arr[] = "vardhaman viroje";
    char buffer[512];

    pipe(fd);

    iRet = fork();
    if (iRet == 0)
    {
        printf("Child process writing into pipe\n");
        close(fd[0]);
        write(fd[1], arr, strlen(arr));
        exit(0);
    }
    else
    {
        close(fd[1]);
        read(fd[0], buffer, sizeof(buffer));
        printf("parent process reading from pipe:%s\n",buffer);
    }
    return 0;
}

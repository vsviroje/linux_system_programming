#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define ReadEnd 0
#define WriteEnd 1

int main()
{
    int pipeFDs[2];
    char buf;
    const char *msg = "vardhaman viroje\n";

    if (pipe(pipeFDs) < 0)
    {
        perror("Pipe creation failed");
        exit(-1);
    }

    pid_t cpid = fork();
    if (cpid < 0)
    {
        perror("fork failed");
        exit(-1);
    }

    if (0 == cpid)
    {
        printf("child process running\n");
        close(pipeFDs[WriteEnd]);
        printf("Data recieved by child:\n");

        while (read(pipeFDs[ReadEnd], &buf, 1) > 0)
        {
            write(STDOUT_FILENO, &buf, sizeof(buf));
        }

        close(pipeFDs[ReadEnd]);
        exit(0);
    }
    else
    {
        printf("parent process running\n");
        close(pipeFDs[ReadEnd]);

        write(pipeFDs[WriteEnd], msg, strlen(msg));

        close(pipeFDs[WriteEnd]);
        printf("Data written into pipe by parent\n");

        wait(NULL);
        exit(0);
    }

    return 0;
}
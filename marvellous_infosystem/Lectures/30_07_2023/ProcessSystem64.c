#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

extern char **environ;
int main()
{
    char buffer[512] = {'\0'};
    int iCnt = 0, iRet = 0, i = 0, fd = 0;

    fd = open("Demo.txt", O_RDONLY);

    while ((iRet = read(fd, buffer, sizeof(buffer))) != 0)
    {
        for (i = 0; i < iRet; i++)
        {
            if ((buffer[i] >= 'a') && (buffer[i] <= 'z'))
            {
                iCnt++;
            }
        }
    }

    printf("Num of Small case :%d\n", iCnt);

    close(fd);
    return 0;
}
/*

*/
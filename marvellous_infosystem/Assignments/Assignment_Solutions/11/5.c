#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/wait.h>

/*
prototype to use thread func
void *NameOfFunction(void *VariableName){}
*/

void *ThreadProc(void *ptr)
{
    const char capA = 'A';
    const char capZ = 'Z';
    const char smalla = 'a';
    const char smallz = 'z';

    char startLetter, endLettter;
    char **inputs = (char **)ptr;
    int iCnt = 0, iRet = 0, i = 0, fd = 0;

    char buffer[512] = {'\0'};
    char fileName[50] = {'\0'};

    if (inputs[0][0] == 'C') // C-capitals and S-small
    {
        startLetter = capA;
        endLettter = capZ;
    }
    else
    {
        startLetter = smalla;
        endLettter = smallz;
    }

    fd = open(inputs[1], O_RDONLY);

    while ((iRet = read(fd, buffer, sizeof(buffer))) != 0)
    {
        for (i = 0; i < iRet; i++)
        {
            if ((buffer[i] >= startLetter) && (buffer[i] <= endLettter))
            {
                iCnt++;
            }
        }
    }

    printf("%c case Count :%d\n", inputs[0][0], iCnt);

    close(fd);

    pthread_exit(NULL);
}

// Multithread demonstration
int main()
{
    pthread_t tid1, tid2;
    int ret1 = 0, ret2 = 0;
    char *inputs1[2];
    char *inputs2[2];

    inputs1[0] = "C";
    inputs1[1] = "demo.txt";

    ret1 = pthread_create(&tid1,      // Address of pthread_t structure object
                          NULL,       // Thread attributes
                          ThreadProc, // Address of callback function
                          &inputs1);  // Parameters to callback function

    if (ret1 != 0)
    {
        printf("Failed to create thread1\n");
        return -1;
    }

    inputs2[0] = "S";
    inputs2[1] = "demo.txt";

    ret2 = pthread_create(&tid2,      // Address of pthread_t structure object
                          NULL,       // Thread attributes
                          ThreadProc, // Address of callback function
                          &inputs2);  // Parameters to callback function

    if (ret2 != 0)
    {
        printf("Failed to create thread2\n");
        return -1;
    }

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("End of main thread\n");

    pthread_exit(NULL);

    return 0;
}

/*
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/11$ gcc 5.c -lpthread 
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/11$ ./a.out 
C case Count :24
S case Count :392
End of main thread
*/
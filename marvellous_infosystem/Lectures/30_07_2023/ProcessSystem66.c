#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
//MultiProcessing demonstration
int main()
{
    int ret1 = 0;
    int ret2 = 0;
    ret1 = fork();

    if (ret1 == 0) // child
    {
        execl("./Process1", "NULL", NULL);
    }

    ret2 = fork();

    if (ret2 == 0) // child
    {
        execl("./Process2", "NULL", NULL);
    }
    return 0;
}
/*
vsviroje@viroje-Inspiron-15-7000-Gaming:~/Documents/Marvellous-LSP-2023/Lecture/30_07_2023$ gcc ProcessSystem66.c 
vsviroje@viroje-Inspiron-15-7000-Gaming:~/Documents/Marvellous-LSP-2023/Lecture/30_07_2023$ ./a.out 
Num of Small case :127
Num of Capital case :11
*/
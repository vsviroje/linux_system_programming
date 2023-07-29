#include "sharedFile.h"
void isNumberPrime(int N)
{
    int flag = 1;

    for (int i = 2; i <= N / 2; i++)
    {

        if (N % i == 0)
        {
            flag = 0;
            break;
        }
    }

    if (flag)
    {
        printf("The number %d is a Prime Number\n", N);
    }
    else
    {
        printf("The number %d is not a Prime Number\n", N);
    }

    return;
}

/*
to generate .o file
gcc -c -fPIC sharedFile1.c

to generate .so file
gcc -shared -o library1.so sharedFile1.o

display info .so file
nm -g library.so
*/
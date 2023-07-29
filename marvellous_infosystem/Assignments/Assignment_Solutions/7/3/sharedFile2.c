#include "sharedFile.h"

void isNumberPerfect(int n)
{
    int i = 1, sum = 0;

    while (i < n)
    {
        if (n % i == 0)
            sum = sum + i;
        i++;
    }
    if (sum == n)
        printf("%d is a perfect number\n", i);
    else
        printf("%d is not a perfect number\n", i);

}

/*
to generate .o file
gcc -c -fPIC sharedFile2.c

to generate .so file
gcc -shared -o library2.so sharedFile2.o

display info .so file
nm -g library.so
*/
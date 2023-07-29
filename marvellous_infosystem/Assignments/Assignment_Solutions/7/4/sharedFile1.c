#include "sharedFile.h"

void factorialWrapper(int n)
{
    void *ptr = NULL;

    long (*factorial)(int);

    ptr = dlopen("./library2.so", RTLD_LAZY);
    if (ptr == NULL)
    {
        printf("unable to load library2.so\n");
        return;
    }


    factorial = dlsym(ptr, "factorial");
    if (factorial == NULL)
    {
        printf("unable to load address of isNumberPrime function\n");
        return;
    }

    printf("factorial of %d is %ld\n",n,factorial(n));

    return ;
}

/*
to generate .o file
gcc -c -fPIC sharedFile1.c

to generate .so file
gcc -shared -o library1.so sharedFile1.o

display info .so file
nm -g library.so
*/
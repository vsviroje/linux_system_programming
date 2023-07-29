#include "sharedFile.h"

int Addition(int a, int b)
{
    return a + b;
}

int Subtraction(int a, int b)
{
    return a - b;
}

int Multiplication(int a, int b)
{
    return a * b;
}

int Division(int a, int b)
{
    return a / b;
}

/*
to generate .o file
gcc -c -fPIC sharedFile.c

to generate .so file
gcc -shared -o library.so sharedFile.o

display info .so file
nm -g library.so
*/
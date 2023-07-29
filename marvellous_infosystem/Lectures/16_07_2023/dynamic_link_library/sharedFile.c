#include<stdio.h>
#include"sharedFile.h"

void Display()
{
    printf("Jai Jinendra...\n");
}

/*
to generate .o file
gcc -c -fPIC sharedFile.c

to generate .so file
gcc -shared -o library.so sharedFile.o

display info .so file
nm -g library.so
*/
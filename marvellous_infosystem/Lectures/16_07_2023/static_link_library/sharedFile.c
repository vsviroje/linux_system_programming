#include"sharedFile.h"

int Addition(int a,int b)
{
    return a+b;
}

/*
to generate .c to .o file
gcc -c sharedFile.c -o sharedFile.o

to generate .o to .a file
ar rcs sharedFile.a sharedFile.o
*/
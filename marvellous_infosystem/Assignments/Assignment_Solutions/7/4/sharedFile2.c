#include "sharedFile.h"

long factorial(int n)  
{  
  if (n == 0)  
    return 1;  
  else  
    return(n * factorial(n-1));  
}

/*
to generate .o file
gcc -c -fPIC sharedFile2.c

to generate .so file
gcc -shared -o library2.so sharedFile2.o

display info .so file
nm -g library.so
*/
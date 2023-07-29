#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main()
{
    void *ptr = NULL;
    void (*fptr)();

    ptr = dlopen("./library.so", RTLD_LAZY);
    if (ptr == NULL)
    {
        printf("unable to load liabrary\n");
        return -1;
    }

    fptr = dlsym(ptr, "Display");
    if (fptr == NULL)
    {
        printf("unable to load address of function\n");
        return -1;
    }

    fptr();
    return 0;
}

/*
//run file client code
gcc client.c  -rdynamic -o myexe
or
gcc client.c  -ldl -o myexe
*/

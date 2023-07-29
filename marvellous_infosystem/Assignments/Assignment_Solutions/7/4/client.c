#include "sharedFile.h"

int main(int argc, char *argv[])
{
    void *ptr = NULL;

    int n = 0;

    void (*factorialWrapper)(int);

    ptr = dlopen("./library1.so", RTLD_LAZY);
    if (ptr == NULL)
    {
        printf("unable to load liabrary1.so\n");
        return -1;
    }

    factorialWrapper = dlsym(ptr, "factorialWrapper");
    if (factorialWrapper == NULL)
    {
        printf("unable to load address of factorialWrapper function\n");
        return -1;
    }

    printf("Enter number:\n");
    scanf("%d", &n);

    factorialWrapper(n);

    return 0;
}

/*
//run file client code
gcc client.c  -rdynamic -o myexe
or
gcc client.c  -ldl -o myexe
*/

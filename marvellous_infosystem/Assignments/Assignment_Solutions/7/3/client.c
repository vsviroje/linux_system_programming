#include "sharedFile.h"

int main(int argc, char *argv[])
{
    void *ptr1 = NULL;
    void *ptr2 = NULL;

    int n = 0;

    void (*isNumberPrime)(int);
    void (*isNumberPerfect)(int);

    ptr1 = dlopen("./library1.so", RTLD_LAZY);
    if (ptr1 == NULL)
    {
        printf("unable to load liabrary1.so\n");
        return -1;
    }

    ptr2 = dlopen("./library2.so", RTLD_LAZY);
    if (ptr2 == NULL)
    {
        printf("unable to load liabrary2.so\n");
        return -1;
    }

    isNumberPrime = dlsym(ptr1, "isNumberPrime");
    if (isNumberPrime == NULL)
    {
        printf("unable to load address of isNumberPrime function\n");
        return -1;
    }

    isNumberPerfect = dlsym(ptr2, "isNumberPerfect");
    if (isNumberPerfect == NULL)
    {
        printf("unable to load address of isNumberPerfect function\n");
        return -1;
    }

    printf("Enter number:\n");
    scanf("%d",&n);

    isNumberPerfect(n);
    isNumberPrime(n);

    return 0;
}

/*
//run file client code
gcc client.c  -rdynamic -o myexe
or
gcc client.c  -ldl -o myexe
*/

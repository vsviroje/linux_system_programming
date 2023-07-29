#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main()
{
    void *ptr = NULL;
    int (*addPtr)(int, int);
    int (*subPtr)(int, int);
    int (*mulPtr)(int, int);
    int (*divPtr)(int, int);

    int a = 10, b = 5;

    ptr = dlopen("./library.so", RTLD_LAZY);
    if (ptr == NULL)
    {
        printf("unable to load liabrary\n");
        return -1;
    }

    addPtr = dlsym(ptr, "Addition");
    if (addPtr == NULL)
    {
        printf("unable to load address of Addition function\n");
        return -1;
    }

    subPtr = dlsym(ptr, "Subtraction");
    if (subPtr == NULL)
    {
        printf("unable to load address of Subtraction function\n");
        return -1;
    }

    mulPtr = dlsym(ptr, "Multiplication");
    if (mulPtr == NULL)
    {
        printf("unable to load address of Multiplication function\n");
        return -1;
    }

    divPtr = dlsym(ptr, "Division");
    if (divPtr == NULL)
    {
        printf("unable to load address of Division function\n");
        return -1;
    }

    printf("Add:%d\n",addPtr(a,b));
    printf("Sub:%d\n",subPtr(a,b));
    printf("Mul:%d\n",mulPtr(a,b));
    printf("Div:%d\n",divPtr(a,b));

    return 0;
}

/*
//run file client code
gcc client.c  -rdynamic -o myexe
or
gcc client.c  -ldl -o myexe
*/

#include "sharedFile.h"

int main(int argc, char *argv[])
{
    void *ptr = NULL;
    int (*isFileSamePtr)(char*, char*);

    char srcFNane[100] = {'\0'};
    char dstFNane[100] = {'\0'};

    ptr = dlopen("./library.so", RTLD_LAZY);
    if (ptr == NULL)
    {
        printf("unable to load liabrary\n");
        return -1;
    }

    isFileSamePtr = dlsym(ptr, "isFileSame");
    if (isFileSamePtr == NULL)
    {
        printf("unable to load address of isFileSame function\n");
        return -1;
    }

    if (argc < 3)
    {
        printf("Invalid no of arguments|ActualCount:%d\n", argc);
        while (argc > 0)
        {
            argc--;
            printf("Argument%d:%s\n", argc, argv[argc]);
        }
        return -1;
    }

    strcpy(srcFNane, argv[1]);
    strcpy(dstFNane, argv[2]);

    printf("isFileSamePtr:%d\n", isFileSamePtr(srcFNane, dstFNane));

    return 0;
}

/*
//run file client code
gcc client.c  -rdynamic -o myexe
or
gcc client.c  -ldl -o myexe
*/

#include <stdio.h>
#include "sharedFile.h"

int main()
{
    printf("sum:%d\n",Addition(5,6));
    return 0;
}

/*
//run file client code
gcc -static client.c -o myexe sharedFile.a
*/

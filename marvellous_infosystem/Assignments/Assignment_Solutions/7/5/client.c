#include "sharedFile.h"

int main()
{
    
    char fName[20];

    printf("Enter File name:\n");
    scanf("%s", fName);

    GetFileInfo(fName);

    return 0;
}

/*
//run file client code
gcc -static client.c -o myexe sharedFile.a
*/

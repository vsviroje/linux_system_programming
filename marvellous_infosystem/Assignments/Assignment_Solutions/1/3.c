#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

    int ret = 0;
    int mode = 0;
    char fName[20];
    char fMode[5];

    printf("File name:\n");
    scanf("%s", fName);
    printf("File mode:\n");
    scanf("%s", fMode);

    if (strcmp(fMode, "R") == 0)
    {
        mode = R_OK;
    }
    else if (strcmp(fMode, "W") == 0)
    {
        mode = W_OK;
    }
    else if (strcmp(fMode, "E") == 0)
    {
        mode = X_OK;
    }
    else if (strcmp(fMode, "FE") == 0)
    {
        mode = F_OK;
    }
    else
    {
        printf("Invalid open mode\n");
        return -1;
    }

    ret = access(fName, mode);
    if (ret == -1)
    {
        printf("unable to access file\n");
        return -1;
    }
    else
    {
        printf("Able to access file\n");
    }

    return 0;
}

/*
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/1$ gcc 3.c 
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/1$ ./a.out 
File name:
3.c
File mode:
E
unable to access file
*/

/*
#include <unistd.h>
int access(const char *pathname, int mode);

DESCRIPTION

access() checks whether the calling process can access the file
pathname.  If pathname is a symbolic link, it is dereferenced.

The mode specifies the accessibility check(s) to be performed,
and is either the value F_OK, or a mask consisting of the bitwise
OR of one or more of R_OK, W_OK, and X_OK.  F_OK tests for the
existence of the file.  R_OK, W_OK, and X_OK test whether the
file exists and grants read, write, and execute permissions,
respectively.
*/
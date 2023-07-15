#include <stdio.h>
//argc:argument count
//argv:argument vector/array
int main(int argc, char *argv[])
{
    printf("Application Name %s\n", argv[0]);
    if (argc == 1)
    {
        printf("Please enter 1st command\n");
        return -1;
    }
    else
    {
        printf("Welcome %s\n", argv[1]);
    }
    return 0;
}
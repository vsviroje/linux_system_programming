#include <stdio.h>
int main(int argc, char *argv[])
{
    printf("Jai Jinendra!!!\n");
    if (argc == 2)
    {
        printf("Welcome %s\n", argv[1]);
    }
    else
    {
        printf("cmdline arg missing\n");
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{

    int a = 0, b = 0, ans = 0;

    if (argc < 3)
    {
        printf("Err:Need atleast 2 number");
        return -1;
    }

    a = atoi(argv[1]);
    b = atoi(argv[2]);

    ans = a + b;
    printf("ans:%d\n", ans);

    return 0;
}
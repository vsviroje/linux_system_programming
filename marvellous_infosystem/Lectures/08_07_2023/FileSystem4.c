#include <stdio.h>
int main(int argc, char *argv[])
{
    int a = 0, b = 0, ans = 0;
    printf("Please enter 1st number\n");
    scanf("%d", &a);
    printf("Please enter 2nd number\n");
    scanf("%d", &b);

    ans = a + b;
    printf("ans:%d\n", ans);

    return 0;
}
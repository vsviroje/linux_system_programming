#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
int main()
{
    struct passwd *pw = getpwuid(getuid());
    if (pw == NULL)
    {
        printf("failed to get user details UID:%d\n", getuid());
        return -1;
    }
    printf("UID:%d\n", getuid());
    printf("Home Dir:%s\n", pw->pw_dir);
    printf("User Name:%s\n", pw->pw_name);
    return 0;
}
/*
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/9$ gcc 7.c 
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/9$ ./a.out 
UID:1000
Home Dir:/home/vsviroje
User Name:vsviroje
*/
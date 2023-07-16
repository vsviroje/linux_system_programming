#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#pragma pack(1)
struct Student
{
    int RollNo;
    char Sname[20];
    float Marks;
    int Age;
};

int main(int argc, char *argv[])
{
    struct Student sobj;
    char fName[20];
    int fd;

    printf("Enter File name:\n");
    scanf("%s", fName);

    fd = open(fName, O_RDONLY);
    
    read(fd, &sobj, sizeof(sobj));

    printf("RollNo:%d\n",sobj.RollNo);
    printf("Age:%d\n",sobj.Age);
    printf("Sname:%s\n",sobj.Sname);
    printf("Marks:%.2f\n",sobj.Marks);

    close(fd);

    return 0;
}

/*
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/5$ gcc 2.c 
vsviroje@viroje-Inspiron-15-7000-Gaming:~/GitRepo/GitHub/linux_system_programming/marvellous_infosystem/Assignments/Assignment_Solutions/5$ ./a.out 
Enter File name:
temp1
RollNo:69
Age:26
Sname:Vardhaman
Marks:60.50
*/
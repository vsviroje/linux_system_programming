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

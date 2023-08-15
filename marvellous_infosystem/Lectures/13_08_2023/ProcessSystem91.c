#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    char fileName1[30], fileName2[30];
    int ret = 0;

    printf("Enter the existing file name:\n");
    scanf("%s", fileName1);

    printf("Enter the name for hardlink:\n");
    scanf("%s", fileName2);

    ret = link(fileName1, fileName2);

    if (ret == 0)
    {
        printf("sucessfully created hardlink\n");
    }

    return 0;
}

/*
vsviroje@viroje-Inspiron-15-7000-Gaming:~/Desktop/13_08_2023$ gcc ProcessSystem91.c 
vsviroje@viroje-Inspiron-15-7000-Gaming:~/Desktop/13_08_2023$ ./a.out 
Enter the existing file name:
demo.txt
Enter the name for hardlink:
temp.txt
sucessfully created hardlink
vsviroje@viroje-Inspiron-15-7000-Gaming:~/Desktop/13_08_2023$ stat demo.txt 
  File: demo.txt
  Size: 6               Blocks: 8          IO Block: 4096   regular file
Device: 816h/2070d      Inode: 2771285     Links: 2
Access: (0664/-rw-rw-r--)  Uid: ( 1000/vsviroje)   Gid: ( 1003/vsviroje)
Access: 2023-08-13 08:38:31.177965713 +0530
Modify: 2023-08-13 08:37:23.993962743 +0530
Change: 2023-08-13 08:38:28.161920779 +0530
 Birth: -
vsviroje@viroje-Inspiron-15-7000-Gaming:~/Desktop/13_08_2023$ stat temp.txt 
  File: temp.txt
  Size: 6               Blocks: 8          IO Block: 4096   regular file
Device: 816h/2070d      Inode: 2771285     Links: 2
Access: (0664/-rw-rw-r--)  Uid: ( 1000/vsviroje)   Gid: ( 1003/vsviroje)
Access: 2023-08-13 08:38:31.177965713 +0530
Modify: 2023-08-13 08:37:23.993962743 +0530
Change: 2023-08-13 08:38:28.161920779 +0530
 Birth: -
*/
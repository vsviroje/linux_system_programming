#include <stdio.h>
#include <unistd.h>

int main()
{
    long int page_size = sysconf(_SC_PAGESIZE);
    printf("My page size: %ld\n", page_size);

    void* c1 = sbrk(0);
    printf("program break address: %p\n", c1);
    printf("sizeof char: %lu\n", sizeof(char));

    c1 = (void*) ((char*) c1 + 1);
    printf("c1: %p\n", c1);

    brk(c1);
    void* c2 = sbrk(0);

    printf("program break address: %p\n", c2); 
    return 0;
}
/*
vsviroje@viroje-Inspiron-15-7000-Gaming:~/Documents/Marvellous-LSP-2023/Lecture/01_10_2023$ gcc sbrk.c 
vsviroje@viroje-Inspiron-15-7000-Gaming:~/Documents/Marvellous-LSP-2023/Lecture/01_10_2023$ ./a.out 
My page size: 4096
program break address: 0x559e6d2c2000
sizeof char: 1
c1: 0x559e6d2c2001
program break address: 0x559e6d2c2001
*/
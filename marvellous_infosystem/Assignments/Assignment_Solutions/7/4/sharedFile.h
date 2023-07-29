#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <string.h>

long factorial(int n);
void factorialWrapper(int n);
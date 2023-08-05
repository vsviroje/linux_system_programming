#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
extern char **environ;
int main()
{
    char **env = environ;

    printf("Env of running process is:\n");

    for (; *env != NULL; env++)
    {
        printf("%s\n", *env);
    }
    return 0;
}
/*
extern char **environ;

The variable environ points to an array of pointers to strings
called the "environment".  The last pointer in this array has the
value NULL.  This array of strings is made available to the
process by the execve(2) call when a new program is started.
When a child process is created via fork(2), it inherits a copy
of its parent's environment.

By convention, the strings in environ have the form "name=value".
The name is case-sensitive and may not contain the character "=".
The value can be anything that can be represented as a string.
The name and the value may not contain an embedded null byte
('\0'), since this is assumed to terminate the string.

Environment variables may be placed in the shell's environment by
the export command in sh(1), or by the setenv command if you use
csh(1).
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h> //format of directory entries

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;

    if (argc < 2)
    {
        printf("Invalid Num of argument\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if (dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }
    printf("----------------------------------------------------------\n");
    printf("ls -i: \n");
    printf("----------------------------------------------------------\n");
    printf("Inode Number\tFile Name\n");

    while ((entry = readdir(dp)) != NULL)
    {
        printf("%7lu:%20s\n", entry->d_ino, entry->d_name);
    }

    printf("----------------------------------------------------------\n");
    closedir(dp);

    return 0;
}

/*
The internal format of directories is unspecified.

The <dirent.h> header shall define the following type:

DIR     A type representing a directory stream. The DIR type may
        be an incomplete type.

It shall also define the structure dirent which shall include the
following members:

    ino_t  d_ino       File serial number.
    char   d_name[]    Filename string of entry.

The <dirent.h> header shall define the ino_t type as described in
<sys/types.h>.
*/

/*
opendir, fdopendir - open a directory

DIR *opendir(const char *name);
DIR *fdopendir(int fd);

DESCRIPTION

    The opendir() function opens a directory stream corresponding to
    the directory name, and returns a pointer to the directory
    stream.  The stream is positioned at the first entry in the
    directory.

    The fdopendir() function is like opendir(), but returns a
    directory stream for the directory referred to by the open file
    descriptor fd. 
*/

/*
closedir - close a directory

int closedir(DIR *dirp);

DESCRIPTION
    The closedir() function closes the directory stream associated
    with dirp.  A successful call to closedir() also closes the
    underlying file descriptor associated with dirp.
*/

/*
readdir - read a directory

struct dirent *readdir(DIR *dirp);

DESCRIPTION
    The readdir() function returns a pointer to a dirent structure
    representing the next directory entry in the directory stream
    pointed to by dirp.  It returns NULL on reaching the end of the
    directory stream or if an error occurred.
*/
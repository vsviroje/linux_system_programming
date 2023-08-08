#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/msg.h>
#include <stdlib.h>

struct my_msg_st
{
    long int my_msg_type;
    char some_text[BUFSIZ];
};

int main()
{
    int running = 1, msgid;
    struct my_msg_st some_data;
    long int msg_to_receive = 0;

    printf("Demo client msg queue\n");

    msgid = msgget((key_t)1234, 0666);
    if (msgid == -1)
    {
        printf("msgget failed\n");
        exit(EXIT_FAILURE);
    }

    printf("ready to fetch msg from queue\n");

    while (running)
    {

        msgrcv(msgid, (void *)&some_data, BUFSIZ, msg_to_receive, 0);
        printf("Received msg:%s\n", some_data.some_text);

        if (strncmp(some_data.some_text, "end", 3) == 0)
        {
            running = 0;
        }
    }
    printf("application closed\n");
    exit(EXIT_SUCCESS);
}
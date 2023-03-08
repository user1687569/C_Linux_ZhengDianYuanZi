#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
#if 0
    execl("/bin/ps", "ps", "-ef", NULL);
    perror("execl error");
#else
    char *arg_arr[5];

    arg_arr[0] = "ls";
    arg_arr[1] = "-a";
    arg_arr[2] = "-l";
    arg_arr[3] = NULL;
    execv("/bin/ls", arg_arr);
    perror("execv error");
#endif

    exit(-1);
}


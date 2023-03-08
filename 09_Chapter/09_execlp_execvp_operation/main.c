#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
#if 0
    execlp("ls", "ls", "-a", "-l", NULL);
    perror("execlp error");
    exit(-1);
#else
    char *arg_arr[5];

    arg_arr[0] = "ps";
    arg_arr[1] = "-ef";
    arg_arr[2] = NULL;
    execvp("ps", arg_arr);

    perror("execvp error");
    exit(-1);
#endif
}


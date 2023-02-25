#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    int pid;

    printf("kill example...\n");
    if(argc < 2)
        exit(-1);

    pid = atoi(argv[1]);
    printf("pid:%d\n", pid);

    if(kill(pid, SIGINT) == -1)
    {
        perror("kill error");
        exit(-1);
    }

    return 0;
}

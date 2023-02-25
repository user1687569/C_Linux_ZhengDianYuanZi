#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static void sig_handler(int sig)
{
    printf("Received signal:%d\n", sig);
}

int main()
{
    struct sigaction sig = {0};
    int ret;

    sig.sa_handler = sig_handler;
    sig.sa_flags = 0;

    ret = sigaction(SIGINT, &sig, NULL);
    if(ret == -1)
    {
        perror("sigaction error");
        exit(-1);
    }

    for(;;) {}

    return 0;
}


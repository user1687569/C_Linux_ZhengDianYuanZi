#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static void sig_handler(int sig)
{
    printf("Received signal:%d\n", sig);
}


int main()
{
    sig_t ret = NULL;

    ret = signal(SIGINT, (sig_t)sig_handler);
    if(ret == SIG_ERR)
    {
        perror("signal error");
        exit(-1);
    }

    for(;;){}

    return 0;
}

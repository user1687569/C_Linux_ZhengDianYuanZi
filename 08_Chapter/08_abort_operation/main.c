#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


static void sig_handler(int sig)
{
    printf("接收到信号:%d\n", sig);
}


int main()
{
    struct sigaction sig = {0};

    sig.sa_handler = sig_handler;
    sig.sa_flags = 0;
    if(sigaction(SIGABRT, &sig, NULL) == -1){
        perror("sigaction error");
        exit(-1);
    }

    sleep(2);
    abort();

    for(;;)
        sleep(1);

    exit(0);
}

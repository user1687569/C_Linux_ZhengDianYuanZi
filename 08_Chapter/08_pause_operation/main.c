#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void sig_handler(int sig)
{
    (void)sig;
    puts("Alarm timeout");
}

int main()
{
    struct sigaction sig = {0};
    int second;
    sigset_t sig_set;

    sig.sa_handler = sig_handler;
    sig.sa_flags = 0;
    if(sigaction(SIGALRM, &sig, NULL)){
        perror("sigaction error");
        exit(-1);
    }

    second = 5;
    printf("定时时长:%d秒\n", second);
    alarm(second);

    pause();
    puts("休眠结束");

    return 0;
}

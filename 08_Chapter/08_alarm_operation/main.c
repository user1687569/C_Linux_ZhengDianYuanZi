#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void sig_handler(int sig)
{
    puts("Alarm timeout");
    exit(0);
}

int main()
{
    struct sigaction sig = {0};
    int second;

    char *argv[] = {"0", "3"};

    sig.sa_handler = sig_handler;
    sig.sa_flags = 0;
    if(sigaction(SIGALRM, &sig, NULL) == -1){
        perror("sigaction error");
        exit(-1);
    }

    second = atoi(argv[1]);
    printf("定时时长:%d秒\n", second);
    alarm(second);

    for(;;)
        sleep(1);

    exit(0);
}

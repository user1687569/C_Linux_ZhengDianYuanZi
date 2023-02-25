#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void sig_handler(int sig, siginfo_t *info, void *context)
{
    sigval_t sig_val = info->si_value;

    printf("接收到实时信号:%d\n", sig);
    printf("伴随数据为:%d\n", sig_val.sival_int);
}

int main(int argc, char *argv[])
{
    struct sigaction sig = {0};
    int num;

    /* 判断传参个数 */
    if(argc < 2)
        exit(-1);

    /* 获取用户传递的参数 */
    num = atoi(argv[1]);

    /* 为实时信号绑定处理函数 */
    sig.sa_sigaction = sig_handler;
    sig.sa_flags = SA_SIGINFO;
    if(sigaction(num, &sig, NULL) == -1){
        perror("sigaction error");
        exit(-1);
    }

    for(;;)
        sleep(1);

    exit(0);
}




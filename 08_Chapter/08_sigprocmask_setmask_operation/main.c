#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void sig_handler(int sig)
{
    (void)sig;
    printf("执行信号处理函数......\n");
}

int main()
{
    struct sigaction sig = {0};
    sigset_t sig_set, old_set;

    /* 注册信号处理函数 */
    sig.sa_handler = sig_handler;
    sig.sa_flags = 0;
    if(sigaction(SIGINT, &sig, NULL) == -1)
        exit(-1);

    /* 信号集初始化 */
    sigemptyset(&sig_set);
    sigaddset(&sig_set, SIGINT);

    /* 向信号掩码中添加信号 */
    if(sigprocmask(SIG_BLOCK, &sig_set, NULL))
        exit(-1);

    /* 向自己发送信号 */
    raise(SIGINT);

    /* 受保护的关键代码段 */
    printf("受保护的关键代码段\n");
    sleep(2);

    /* 恢复信号掩码 */
    if(sigprocmask(SIG_SETMASK, &old_set, NULL))
        exit(-1);

    return 0;
}









#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void sig_handler(int sig)
{
    (void)sig;
    printf("执行信号处理函数...\n");
}

int main()
{
    struct sigaction sig = {0};
    sigset_t new_mask, old_mask, wait_mask;

    /* 信号集初始化 */
    sigemptyset(&new_mask);     /* sigemptyset, sigaddset, sigfillset成功返回0, 失败将返回-1, 并设置errno */
    sigaddset(&new_mask, SIGINT);
    sigemptyset(&wait_mask);

    /* 注册信号处理函数 */
    sig.sa_handler = sig_handler;
    sig.sa_flags = 0;
    /* sigaction:成功返回0，失败将返回-1,并设置errno */
    if(sigaction(SIGINT, &sig, NULL) == -1)
        exit(-1);

    /* 向信号掩码中添加信号 */
    if(sigprocmask(SIG_BLOCK, &new_mask, &old_mask) == -1)
        exit(-1);

    /* 执行保护代码段 */
    puts("执行保护代码段\n");
    puts("new new new\n");

    /* 挂起、等待信号唤醒 */
    /* sigsuspend始终返回-1;如果不返回-1,表示调用失败 */
    if(sigsuspend(&wait_mask) != -1){
        printf("退出\n");
        exit(-1);
    }

    printf("恢复信号掩码\n");
    /* 恢复信号掩码 */
    if(sigprocmask(SIG_SETMASK, &old_mask, NULL) == -1)
        exit(-1);

    return 0;
}


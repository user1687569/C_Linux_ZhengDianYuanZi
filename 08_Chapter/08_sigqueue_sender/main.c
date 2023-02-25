#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char *argv[])
{
    union sigval sig_val;
    int pid, sig;

    if(argc < 3)
        exit(-1);

    pid = atoi(argv[1]);
    sig = atoi(argv[2]);
    printf("pid:%d\nsignal:%d\n", pid, sig);

    /* 发送信号 */
    sig_val.sival_int = 10; /* 伴随数据 */
    if(sigqueue(pid, sig, sig_val) == -1){
        perror("sigqueue error");
        exit(-1);
    }

    puts("信号发送成功!\n");
    exit(0);
}

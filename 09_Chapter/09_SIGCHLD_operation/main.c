#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


static void wait_child(int sig)
{
    /* 替子进程收尸 */
    printf("父进程回收子进程\n");
    while(waitpid(-1, NULL, WNOHANG) > 0)
        continue;
}

int main()
{
    struct sigaction sig = {0};

//    sigemptyset(sig.sa_mask);
    sig.sa_handler = wait_child;
    sig.sa_flags = 0;

    if(sigaction(SIGCHLD, &sig, NULL) == -1){
        perror("sigaction error");
        exit(-1);
    }

    /* 创建子进程 */
    switch (fork()) {
    case -1:
        perror("fork error");
        exit(-1);
    case 0:
        printf("子进程<%d>被创建\n", getpid());
        sleep(1);
        printf("子进程结束\n");
        _exit(0);
    default:
        break;
    }

    sleep(3);
    exit(0);
}




#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
 * 检测孤儿进程
 */
int main()
{
    switch (fork()) {
    case -1:
        perror("fork error");
        exit(-1);
    case 0:
        /* 子进程 */
        printf("子进程<%d>被创建，父进程<%d>\n", getpid(),
               getppid());
        sleep(3);
        printf("父进程<%d>\n", getppid());
        _exit(0);
    default:
        /* 父进程 */
        break;
    }

    sleep(1);
    printf("父进程结束!\n");
    exit(0);
}



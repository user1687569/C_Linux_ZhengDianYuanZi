#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int status;
    int ret, i;

    for(i = 1; i <= 3; i++){
        switch (fork()) {
        case -1:
            perror("fork error");
            exit(-1);
        case 0:
            printf("[%d]子进程<%d>被创建\n", i, getpid());
            sleep(i);
            _exit(i);
        default:
            printf("父进程[%d]\n", i);
            break;
        }
    }

    sleep(1);
    printf("-----------------------\n");
    for(i = 1; i <= 3; i++){
        ret = wait(&status);
        if(ret == -1){
            if(errno == ECHILD){
                printf("没有需要等待回收的子进程\n");
                exit(0);
            }
            else{
                perror("wait error");
                exit(-1);
            }
        }
    }

    printf("回收子进程<%d>,终止状态<%d>\n", ret, WEXITSTATUS(status));
    exit(0);
}




























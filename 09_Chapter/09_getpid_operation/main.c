#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid = getpid();
    printf("本进程的PID为:%d\n\n", pid);

    pid = getppid();
    printf("父进程的PID为:%d\n", pid);

    return 0;
}



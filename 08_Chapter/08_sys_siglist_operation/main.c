#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

int main()
{
    printf("SIGINT描述信息:%s\n", sys_siglist[SIGINT]);
    printf("SIGQUIT描述信息:%s\n", sys_siglist[SIGQUIT]);
    printf("SIGBUS描述信息:%s\n", sys_siglist[SIGBUS]);

    return 0;
}

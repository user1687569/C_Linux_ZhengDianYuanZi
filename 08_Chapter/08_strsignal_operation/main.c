#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

int main()
{
    printf("SIGINT描述信息:%s\n", strsignal(SIGINT));
    printf("SIGQUIT描述信息:%s\n", strsignal(SIGQUIT));
    printf("编号为100的描述信息:%s\n", strsignal(100));

    return 0;
}


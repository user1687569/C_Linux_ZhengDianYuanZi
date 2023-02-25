#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

int main()
{
    psignal(SIGINT, "SIGINT信号描述信息");
    psignal(SIGQUIT, "SIGQUIT信号描述信息");
    psignal(SIGBUS, "SIGBUS信号描述信息");

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    struct tm local_t;
    char tm_str[100] = {0};
    timer_t sec;

    sec = time(NULL);
    if(sec == -1)
    {
        perror("time error");
        exit(-1);
    }

    localtime_r(&sec, &local_t);
    strftime(tm_str, sizeof(tm_str), "%Y-%m-%d %A %H:%M:%S", &local_t);
    printf("本地时间:%s\n", tm_str);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main()
{
    struct tm local_t;
    timer_t sec;

    sec = time(NULL);
    if(sec == -1)
    {
        perror("time error");
        exit(-1);
    }

    printf("获取得到的秒数:%ld\n", sec);
    localtime_r(&sec, &local_t);
    printf("转换得到的秒数:%ld\n", mktime(&local_t));

    sleep(2);
    char tm_str[100] = {0};
    sec = time(NULL);
    if(sec == -1)
    {
        perror("time error");
        exit(-1);
    }

    localtime_r(&sec, &local_t);
    asctime_r(&local_t, tm_str);
    printf("本地时间:%s\n", tm_str);

    return 0;
}

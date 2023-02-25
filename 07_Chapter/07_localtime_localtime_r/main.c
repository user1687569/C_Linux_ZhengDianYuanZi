#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    struct tm local_t;
    struct tm utc_t;
    time_t sec;

    /*
     * 获取时间
     */
    sec = time(NULL);
    if(sec == -1)
    {
        perror("time error");
        exit(-1);
    }

    /*
     * 转换得到本地时间
     */
    localtime_r(&sec, &local_t);

    /*
     * 转换得到国际标准时间
     */
    gmtime_r(&sec, &utc_t);

    printf("本地时间: %d年%d月%d日 %02d:%02d:%02d\n",
           local_t.tm_year+1900, local_t.tm_mon+1, local_t.tm_mday,
           local_t.tm_hour, local_t.tm_min, local_t.tm_sec);

    printf("UTC时间: %d年%d月%d日 %02d:%02d:%02d\n",
           utc_t.tm_year+1900, utc_t.tm_mon+1, utc_t.tm_mday,
           utc_t.tm_hour, utc_t.tm_min, utc_t.tm_sec);

    return 0;
}


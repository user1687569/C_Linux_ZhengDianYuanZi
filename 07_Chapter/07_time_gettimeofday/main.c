#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

int main()
{
    time_t t, tt;

    t = time(&tt);
    if(t == -1)
    {
        perror("time error");
        exit(-1);
    }
    printf("时间值:t=%ld,tt=%ld\n", t, tt);

    struct timeval tval;
    int ret;
    ret = gettimeofday(&tval, NULL);
    if(ret == -1)
    {
        perror("gettimeofday error");
        exit(-1);
    }
    printf("时间值:%ld秒 + %ld微秒\n", tval.tv_sec, tval.tv_usec);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>
#include <unistd.h>

int main()
{
    struct tms t_buf_start;
    struct tms t_buf_end;
    clock_t t_start;
    clock_t t_end;
    long tck;
    int i, j;

    /*获取系统的节拍率*/
    tck = sysconf(_SC_CLK_TCK);

    /*开始时间*/
    t_start = times(&t_buf_start);
    if(t_start == -1)
    {
        perror("times error");
        exit(-1);
    }

    for(i = 0; i < 20000; i++)
        for(j = 0; j < 20000; j++)
            ;

    sleep(1);

    /*结束时间*/
    t_end = times(&t_buf_end);
    if(t_end == -1)
    {
        perror("times error");
        exit(-1);
    }

    /*打印时间*/
    printf("节拍率:%f\n", (double)tck);
    printf("时间总和:%f秒\n", (t_end - t_start)/(double)tck);
    printf("用户CPU时间:%f秒\n",
           (t_buf_end.tms_utime - t_buf_start.tms_utime)/(double)tck);
    printf("系统CPU时间:%f秒\n",
           (t_buf_end.tms_stime - t_buf_start.tms_stime)/(double)tck);

    return 0;
}

















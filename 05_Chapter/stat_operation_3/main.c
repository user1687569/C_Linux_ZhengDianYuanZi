#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    struct stat file_stat;
    struct tm file_tm;
    char time_str[100];
    int ret;

    /*
     * 获取文件属性
     */
    ret = stat("./test_file", &file_stat);
    if(ret == -1)
    {
        perror("stat error");
        exit(-1);
    }

    localtime_r(&file_stat.st_atim.tv_sec, &file_tm);
    strftime(time_str, sizeof(time_str),
             "%Y-%m-%d %H:%M:%S", &file_tm);
    printf("time of last access:%s\n", time_str);

    localtime_r(&file_stat.st_mtim.tv_sec, &file_tm);
    strftime(time_str, sizeof(time_str),
             "%Y-%m-%d %H:%M:%S", &file_tm);
    printf("time of last modification:%s\n", time_str);

    localtime_r(&file_stat.st_ctim.tv_sec, &file_tm);
    strftime(time_str, sizeof(time_str),
             "%Y-%m-%d %H:%M:%S", &file_tm);
    printf("time of last status change:%s\n", time_str);

    exit(0);
}



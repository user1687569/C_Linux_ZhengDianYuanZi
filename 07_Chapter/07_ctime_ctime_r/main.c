#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int main()
{
    char tm_str[100] = {0};
    char *ptr = NULL;
    timer_t tm;

    tm = time(NULL);
    if(tm == -1)
    {
        perror("time error");
        exit(-1);
    }
    ptr = ctime(&tm);
    if(ptr == NULL)
    {
        perror("ctime error!");
        exit(-1);
    }
    printf("ctime result:%s\n", ptr);

    sleep(3);
    tm = time(NULL);
    if(tm == -1)
    {
        perror("time error");
        exit(-1);
    }
    ctime_r(&tm, tm_str);
    printf("ctime_r result:%s\n", tm_str);

    return 0;
}

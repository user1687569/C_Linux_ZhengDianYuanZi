#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    struct tm t;
    time_t sec;

    sec = time(NULL);
    if(sec == -1)
    {
        perror("time error");
        exit(-1);
    }
    localtime_r(&sec, &t);



    return 0;
}

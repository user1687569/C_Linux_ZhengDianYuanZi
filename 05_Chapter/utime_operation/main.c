#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <utime.h>
#include <sys/types.h>

#define FILENAME    "./test_file"

int main()
{
    struct utimbuf utm_buf;
    time_t cur_sec;
    int ret;

    ret = access(FILENAME, F_OK);
    if(ret == -1)
    {
        printf("Error:%s file does not exist!\n", FILENAME);
        exit(-1);
    }

    time(&cur_sec);
    utm_buf.actime = cur_sec;
    utm_buf.modtime = cur_sec;

    ret = utime(FILENAME, &utm_buf);
    if(ret == -1)
    {
        perror("utime error");
        exit(-1);
    }

    exit(0);
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>

#define FILENAME    "./test_file"

int main()
{
    struct timeval tmval_arr[2];
    time_t cur_sec;
    int ret, i;

    ret = access(FILENAME, F_OK);
    if(ret == -1)
    {
        printf("Error: %s file does not exist!\n", FILENAME);
        exit(-1);
    }

    time(&cur_sec);
    for(i = 0; i < 2; i++)
    {
        tmval_arr[i].tv_sec = cur_sec;
        tmval_arr[i].tv_usec = 0;
    }

    ret = utimes(FILENAME, tmval_arr);
    if(ret == -1)
    {
        perror("utimes error");
        exit(-1);
    }

    exit(0);
}

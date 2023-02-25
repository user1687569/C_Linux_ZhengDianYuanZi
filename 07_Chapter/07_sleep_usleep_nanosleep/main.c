#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main()
{
    printf("sleep Start. sleep 3 seconds...\n");
    sleep(3);
    printf("sleep end.");

    printf("sleep Start. sleep 3 seconds...\n");
    usleep(3*1000*1000);
    printf("sleep end.");

    struct timespec request_t;
    printf("sleep Start. sleep 3 seconds...\n");
    request_t.tv_sec = 3;
    request_t.tv_nsec = 0;
    nanosleep(&request_t, NULL);
    printf("sleep end.");

    return 0;
}

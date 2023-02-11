#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

static char buf[8192] __attribute((aligned(4096)));

int main()
{
    int fd, count;

//    fd = open("./test_file", O_WRONLY|O_CREAT|O_TRUNC|O_DIRECT, 0664);
    fd = open("./test_file", O_WRONLY|O_CREAT|O_TRUNC, 0664);
    if(fd < 0)
    {
        perror("open error");
        exit(-1);
    }

    count = 10000;
    while (count--)
    {
        if(4096 != write(fd, buf, 4096))
        {
            perror("write error");
            exit(-1);
        }
    }

    close(fd);
    exit(0);
}

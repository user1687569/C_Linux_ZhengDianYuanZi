#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int fd;
    int ret;

    fd = open("./file1", O_RDWR);
    if(fd == -1)
    {
        perror("open error");
        exit(-1);
    }

    ret = ftruncate(fd, 0);
    if(ret > 0)
    {
        perror("ftruncate error");
        exit(-1);
    }

    ret = truncate("./file2", 1024);
    if(ret > 0)
    {
        perror("truncate error");
        exit(-1);
    }

    close(fd);
    exit(ret);
}

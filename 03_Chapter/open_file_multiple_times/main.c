#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int fd1, fd2, fd3;
    int ret;

    fd1 = open("./test_file", O_RDWR);
    if(fd1 == -1)
    {
        perror("open error");
        exit(-1);
    }

    fd2 = open("./test_file", O_RDWR);
    if(fd2 == -1)
    {
        perror("open error");
        exit(-1);
        goto err1;
    }

    fd3 = open("./test_file", O_RDWR);
    if(fd3 == -1)
    {
        perror("open error");
        exit(-1);
        goto err2;
    }

    printf("%d %d %d\n", fd1, fd2, fd3);
    close(fd3);
    ret = 0;

err2:
    close(fd2);

err1:
    close(fd1);
    exit(ret);
}

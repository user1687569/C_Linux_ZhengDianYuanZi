#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int fcntl_dup_fd();
int fcntl_set_get_flags();

int main()
{
    fcntl_dup_fd();
    fcntl_set_get_flags();
}

int fcntl_dup_fd()
{
    int fd1, fd2;
    int ret;

    printf("\n*****fcntl_dup_fd*****\n");
    fd1 = open("./test_file", O_RDONLY);
    if(fd1 == -1)
    {
        perror("open error");
        exit(-1);
    }

    /*
     * 第三个参数表示复制得到的文件描述符需要大于等于9
     */
    fd2 = fcntl(fd1, F_DUPFD, 9);
    if(fd2 == -1)
    {
        perror("fcntl error");
        exit(-1);
        goto err1;
    }

    printf("fd1:%d, fd2:%d\n", fd1, fd2);

    ret = 0;
    close(fd2);

err1:
    close(fd1);
    return ret;
}


int fcntl_set_get_flags()
{
    int fd;
    int ret, flag;

    printf("\n*****fcntl_set_get_flags*****\n");
    fd = open("./test_file_set_get_flags", O_RDWR);
    if(fd == -1)
    {
        perror("open error");
        exit(-1);
    }

    flag = fcntl(fd, F_GETFL);
    if(flag == -1)
    {
        perror("fcntl F_GETFL error");
        exit(-1);
        goto err;
    }
    printf("flags: 0x%x\n", flag);

    ret = fcntl(fd, F_SETFL, flag | O_APPEND);
    if(ret == -1)
    {
        perror("fcntl F_SETFL error");
        goto err;
    }

    flag = fcntl(fd, F_GETFL);
    if(flag == -1)
    {
        perror("fcntl F_GETFL error");
        exit(-1);
        goto err;
    }
    printf("flags: 0x%x\n", flag);

    ret = 0;
err:
    close(fd);
    return ret;
}


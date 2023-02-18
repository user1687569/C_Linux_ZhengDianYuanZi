#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    unsigned char buffer[100] = {0};
    int fd, ret;

    fd = open("./test_file", O_RDWR);
    if(fd == -1)
    {
        perror("open error");
        exit(-1);
    }

    ret = lseek(fd, 0, SEEK_SET);
    if(ret == -1)
    {
        perror("lseek error");
        goto err;
    }

    memset(buffer, 0x11, sizeof(buffer));
    ret = write(fd, buffer, 10);
    if(ret == -1)
    {
        perror("write error");
        goto err;
    }

    memset(buffer, 0x22, sizeof(buffer));
    ret = pwrite(fd, buffer, sizeof(buffer), 10);
    if(ret == -1)
    {
        perror("pwrite error");
        goto err;
    }

    memset(buffer, 0, sizeof(buffer));
    ret = pread(fd, buffer, 10, 5);
    if(ret == -1)
    {
        perror("pread error");
        goto err;
    }

    ret = lseek(fd, 0, SEEK_CUR);
    if(ret == -1)
    {
        perror("lseek error");
        goto err;
    }

    printf("Current offset:%d\n", ret);
    printf("%x %x %x %x %x\n%x %x %x %x %x", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4],
                                             buffer[5], buffer[6], buffer[7], buffer[8], buffer[9]);
    ret = 0;
err:
    close(fd);
    exit(ret);
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    char buffer[4];
    int fd1, fd2;
    int ret;

//    fd1 = open("./test_file", O_RDWR|O_CREAT|O_EXCL,
//                S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
    fd1 = open("./test_file", O_RDWR|O_CREAT,
                S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
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

    buffer[0] = 0x11;
    buffer[1] = 0x22;
    buffer[2] = 0x33;
    buffer[3] = 0x44;

    ret = write(fd1, buffer, 4);
    if(ret == -1)
    {
        perror("write error");
        goto err2;
    }

    ret = lseek(fd2, 0, SEEK_SET);
    if(ret == -1)
    {
        perror("lssek error");
        goto err2;
    }

    memset(buffer, 0x00, sizeof(buffer));
    ret = read(fd2, buffer, 4);
    if(ret == -1)
    {
        perror("read error");
        goto err2;
    }

    printf("0x%x 0x%x 0x%x 0x%x\n", buffer[0], buffer[1], buffer[2], buffer[3]);
    ret = 0;
err2:
    close(fd2);

err1:
    close(fd1);
    exit(ret);
}

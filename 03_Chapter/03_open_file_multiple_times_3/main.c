#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    unsigned char buffer[4], buffer1[4], buffer2[4];
    int fd1, fd2;
    int ret, i;

    fd1 = open("./test_file", O_RDWR|O_CREAT|O_EXCL,
//    fd1 = open("./test_file", O_RDWR|O_CREAT|O_EXCL|O_APPEND,
                S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
    if(fd1 == -1)
    {
        perror("open error");
        exit(-1);
    }

    fd2 = open("./test_file", O_RDWR);
//    fd2 = open("./test_file", O_RDWR|O_APPEND);
    if(fd2 == -1)
    {
        perror("open error");
        exit(-1);
        goto err1;
    }

    buffer1[0] = 0x11;
    buffer1[1] = 0x22;
    buffer1[2] = 0x33;
    buffer1[3] = 0x44;

    buffer2[0] = 0xAA;
    buffer2[1] = 0xBB;
    buffer2[2] = 0xCC;
    buffer2[3] = 0xDD;

    for(i = 0; i < 4; i++)
    {
        ret = write(fd1, buffer1, sizeof(buffer1));
        if(ret == -1)
        {
            perror("write error");
            goto err2;
        }

        ret = write(fd2, buffer2, sizeof(buffer2));
        if(ret == -1)
        {
            perror("write error");
            goto err2;
        }
    }

    ret = lseek(fd1, 0, SEEK_SET);
    if(ret == -1)
    {
        perror("lssek error");
        goto err2;
    }

    for(i = 0; i < 8; i++)
    {
        memset(buffer, 0, sizeof(buffer));
        ret = read(fd1, buffer, sizeof(buffer));
        if(ret == -1)
        {
            perror("read error");
            goto err2;
        }

        printf("%x%x%x%x\n", buffer[0], buffer[1],
                           buffer[2], buffer[3]);
    }

    printf("\n");
    ret = 0;
err2:
    close(fd2);

err1:
    close(fd1);
    exit(ret);
}

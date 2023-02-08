#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    char buffer[16];
    int fd, ret;

    fd = open("./test_file.txt", O_RDWR|O_APPEND);
    if(fd == -1)
    {
        perror("open error");
        exit(-1);
    }

    memset(buffer, 0x55, sizeof(buffer));
    ret = write(fd, buffer, 4);
    if(ret == -1)
    {
        perror("write error");
        goto err;
    }

    memset(buffer, 0x00, sizeof(buffer));
    ret = lseek(fd, -4, SEEK_END);
    if(ret == -1)
    {
        perror("lseek error");
        goto err;
    }

    ret = read(fd, buffer, 4);
    if(fd == -1)
    {
        perror("read error");
        goto err;
    }

    printf("0x%x 0x%x 0x%x 0x%x\n",
           buffer[0], buffer[1], buffer[2], buffer[3]);
    ret = 0;

err:
    close(fd);
    exit(ret);
}

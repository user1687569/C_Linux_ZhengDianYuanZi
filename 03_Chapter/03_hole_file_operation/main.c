#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int fd, ret;
    char buffer[1024];
    int i;

    fd = open("./hole_file", O_WRONLY|O_CREAT|O_EXCL,
                S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
    if(fd == -1)
    {
        perror("open error");
        exit(-1);
    }

    ret = lseek(fd, 4096, SEEK_SET);
    if(ret == -1)
    {
        perror("lseek error");
        goto err;
    }

    memset(buffer, 0xff, sizeof(buffer));
    for(i = 0; i < 4; i++)
    {
        ret = write(fd, buffer, sizeof(buffer));
        if(ret == -1)
        {
            perror("write error");
            goto err;
        }
    }

    ret = 0;
err:
    close(fd);
    exit(ret);

    return 0;
}

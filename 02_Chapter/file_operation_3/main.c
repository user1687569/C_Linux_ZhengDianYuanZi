#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    char buff[1024];
    int fd;
    int ret;

    fd = open("./new_file.txt", O_WRONLY|O_CREAT|O_EXCL,
                            S_IRWXU|S_IRGRP|S_IROTH);
    if(fd == -1){
        printf("Error: open new_file.txt failed.\n");
        ret = -1;
        goto err;
    }

    ret = lseek(fd, 0, SEEK_SET);
    if(ret == -1)
        goto err;

    memset(buff, 0, sizeof(buff));
    ret = write(fd, buff, sizeof(buff));
    if(ret == -1)
    {
        printf("Error: write 1KB 0x00 to file failed!\n");
        goto err;
    }

    memset(buff, 0xff, sizeof(buff));
    ret = write(fd, buff, sizeof(buff));
    if(ret == -1)
    {
        printf("Error: write 1KB 0xFF to file failed!\n");
        goto err;
    }

    printf("OK! Test successfully.\n");
    ret = 0;

err:
    close(fd);
    return ret;
}

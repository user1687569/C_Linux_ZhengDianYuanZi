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
    int ret = -1;
    off_t off;

    fd = open("./test_file.txt", O_RDONLY, S_IRWXU|S_IRGRP|S_IROTH);
    if(fd == -1){
        printf("Error: open test_file.txt failed.\n");
        ret = -1;
        goto err;
    }

    off = lseek(fd, 0, SEEK_END);
    if(off == -1)
        goto err;

    printf("OK! File size is %d.\n", off);
    ret = 0;

err:
    close(fd);
    return ret;
}

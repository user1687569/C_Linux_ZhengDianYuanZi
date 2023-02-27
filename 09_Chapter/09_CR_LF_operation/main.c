#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int fd;

    fd = open("./test.txt", O_RDWR|O_TRUNC);
    if(fd < 0){
        perror("open error");
        exit(-1);
    }

    write(fd, "ABC", 3);
    fsync(fd);

    write(fd, "\r\n", 2);
    fsync(fd);

    write(fd, "123", 3);
    fsync(fd);

    write(fd, "\r\n", 2);
    fsync(fd);

    close(fd);
}

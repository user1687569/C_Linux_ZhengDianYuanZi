#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    pid_t pid;
    int fd, i;

    fd = open("./test.txt", O_RDWR|O_TRUNC);
    if(fd < 0){
        perror("open error");
        exit(-1);
    }

    pid = fork();
    switch (pid) {
    case -1:
        perror("fork error");
        close(fd);
        exit(-1);
    case 0:
        for(i = 0; i < 4; i++)
            write(fd, "1122", 4);
        close(fd);
        _exit(0);
    default:
        for(i = 0; i < 4; i++)
            write(fd, "AABB", 4);
        close(fd);
        exit(0);
    }

    exit(0);
}





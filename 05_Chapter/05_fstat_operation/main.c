#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    struct stat file_stat;
    int fd, ret;

    fd = open("./test_file", O_RDONLY);
    if(fd == -1)
    {
        perror("open error");
        exit(-1);
    }

    ret = fstat(fd, &file_stat);
    if(ret == -1)
    {
        perror("fstat error");
    }

    printf("[file_stat]\ninode:%d\nUser Id:%d\nGroup Id:%d\nFile Size:%d\n",
           file_stat.st_ino, file_stat.st_uid, file_stat.st_gid, file_stat.st_size);

    close(fd);
    exit(ret);
}

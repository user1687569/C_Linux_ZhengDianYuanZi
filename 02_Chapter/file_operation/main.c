#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char buff[1024];
    int fd1, fd2;
    int ret;

    fd1 = open("./src_file.txt", O_RDONLY);
    if(fd1 == -1)
    {
        printf("Error: open src_file failed.\n");
        return -1;
    }

    fd2 = open("./dest_file.txt", O_WRONLY|O_CREAT|O_EXCL,
                            S_IRWXU|S_IRGRP|S_IROTH);
    if(fd2 == -1){
        printf("Error: open dest_file failed.\n");
        ret = -1;
        goto err2;
    }

    ret = lseek(fd1, 500, SEEK_SET);
    if(ret == -1)
        goto err2;

    ret = read(fd1, buff, sizeof(buff));
    if(ret == -1)
    {
        printf("Error: read src_file failed.\n");
        goto err2;
    }

    ret = lseek(fd2, 0, SEEK_SET);
    if(ret == -1)
        goto err2;

    ret = write(fd2, buff, sizeof(buff));
    if(ret == -1)
    {
        printf("Error: write dest_file failed!\n");
        goto err2;
    }

    printf("OK! Test successfully.\n");
    ret = 0;

err2:
    close(fd2);

err1:
    close(fd1);
    return ret;
}





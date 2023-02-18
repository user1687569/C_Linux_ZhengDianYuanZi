#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void write_test();
void fp_to_fd();
void fd_to_fp();

int main()
{
//    write_test();
//    fp_to_fd();
    fd_to_fp();
    return 0;
}


void write_test()
{
    printf("printf");
    write(STDOUT_FILENO, "write\n", 6);
    exit(0);
}


void fp_to_fd()
{
    FILE *fp = NULL;
    int fd = 0;

    fp = fopen("./test_file", "w+");
    if(fp == NULL)
    {
        perror("fopen error");
        exit(-1);
    }

    fd = fileno(fp);
    printf("File no is: %d\n", fd);

    fclose(fp);
}


void fd_to_fp()
{
    int fd, ret;
    FILE *fp = NULL;
    char buf[] = "test_file_fd_to_fp!\n";

    fd = open("./test_file_fd_to_fp", O_RDWR|O_CREAT|O_EXCL,
                S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
    if(fd == -1)
    {
        perror("open error");
        exit(-1);
    }

    fp = fdopen(fd, "w+");
    if(fp == NULL)
    {
        perror("fdopen error");
        exit(-1);
    }

    ret = fwrite(buf, 1, sizeof(buf), fp);
    if(ret < sizeof(buf))
    {
        printf("fwrite error\n");
        fclose(fp);
        exit(-1);
    }

    printf("数据写入成功!\n");
    fclose(fp);
}

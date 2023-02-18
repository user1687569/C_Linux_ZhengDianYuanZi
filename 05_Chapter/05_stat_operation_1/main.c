#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    struct stat file_stat;
    int ret;

    /*
     * 获取文件属性
     */
    ret = stat("./test_file", &file_stat);
    if(ret == -1)
    {
        perror("stat error");
        exit(-1);
    }

    /*
     * 打印文件大小和inode编号
     */
    printf("file size: %ld bytes\ninode number: %ld\n",
            file_stat.st_size, file_stat.st_ino);
    return 0;
}


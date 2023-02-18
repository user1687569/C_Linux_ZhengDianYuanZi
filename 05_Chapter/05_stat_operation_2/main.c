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

    switch (file_stat.st_mode & S_IFMT) {
    case S_IFSOCK:
        printf("socket");
        break;
    case S_IFLNK:
        printf("symbolic link");
        break;
    case S_IFREG:
        printf("regular file");
        break;
    case S_IFBLK:
        printf("block device");
        break;
    case S_IFDIR:
        printf("directory");
        break;
    case S_IFCHR:
        printf("character device");
        break;
    case S_IFIFO:
        printf("FIFO");
        break;
    default:
        break;
    }

    printf("\n");

    if(file_stat.st_mode & S_IROTH)
        printf("Read: Yes\n");
    else
        printf("Read: No\n");

    if(file_stat.st_mode & S_IWOTH)
        printf("Write: Yes\n");
    else
        printf("Write: No\n");

    exit(0);
}



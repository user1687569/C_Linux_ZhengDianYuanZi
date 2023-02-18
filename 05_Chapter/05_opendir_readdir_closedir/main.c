#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>

int main()
{
    struct dirent *dir;
    DIR *pDir;
    int ret = 0;

    pDir = opendir("./my_dir");
    if(pDir == NULL)
    {
        perror("opendir error");
        exit(-1);
    }

    errno = 0;
    while (NULL != (dir = readdir(pDir)))
    {
        printf("Item Name:%15s|inode:%8ld\n", dir->d_name, dir->d_ino);
    }

    if(errno != 0)
    {
        perror("readdir error");
        ret = -1;
        goto err;
    }
    else
    {
        printf("End of directory!\n");
    }

err:
    closedir(pDir);
    exit(ret);
}

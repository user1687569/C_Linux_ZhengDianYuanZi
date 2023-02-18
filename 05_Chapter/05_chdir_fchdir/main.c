#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    char buf[1024] = {0};
    char *ptr;
    int ret;

    memset(buf, 0x00, sizeof(buf));
    ptr = getcwd(buf, sizeof(buf));
    if(ptr == NULL)
    {
        perror("getcwd error");
        exit(-1);
    }
    printf("Before the change:%s\n", buf);

    ret = chdir("./new_dir");
    if(ret == -1)
    {
        perror("chdir error");
        exit(-1);
    }

    memset(buf, 0x00, sizeof(buf));
    ptr = getcwd(buf, sizeof(buf));
    if(ptr == NULL)
    {
        perror("getcwd error");
        exit(-1);
    }

    printf("After the change: %s\n", buf);
    exit(0);
}


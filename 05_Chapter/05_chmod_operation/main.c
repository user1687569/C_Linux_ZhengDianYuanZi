#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main()
{
    int ret;

    ret = chmod("./test_file", 0777);
    if(ret == -1)
    {
        perror("chmod error");
        exit(-1);
    }
    else
    {
        printf("chmod successfully.\n");
    }

    exit(0);
}

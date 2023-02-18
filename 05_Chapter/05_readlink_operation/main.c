#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    char buf[50] = {0};
    int ret;

    memset(buf, 0x00, sizeof(buf));
    ret = readlink("./soft", buf, sizeof(buf));
    if(ret == -1)
    {
        perror("readlink error");
        exit(-1);
    }

    printf("%s\n", buf);
    return 0;
}

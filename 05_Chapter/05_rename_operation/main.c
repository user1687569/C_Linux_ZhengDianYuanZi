#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ret;

    ret = rename("./test_file", "./lishu/new_file");
    if(ret == -1)
    {
        perror("rename error");
        exit(-1);
    }

    exit(0);
}


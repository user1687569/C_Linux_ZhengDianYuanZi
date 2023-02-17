#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int ret;

    ret = link("./test_file", "./hard");
    if(ret == -1)
    {
        perror("link error");
        exit(-1);
    }

    ret = symlink("./test_file", "./soft");
    if(ret == -1)
    {
        perror("symlink error");
        exit(-1);
    }

    exit(0);
}

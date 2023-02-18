#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int ret;

    ret = unlink("./test_file");
    if(ret == -1)
    {
        perror("unlink error");
        exit(-1);
    }
    else
        fprintf(stdout, "unlink test_file successfuly!");

    exit(0);
}

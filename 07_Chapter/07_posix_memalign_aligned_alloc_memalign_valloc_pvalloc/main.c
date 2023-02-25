#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *base = NULL;
    int ret;

    /*申请内存:256个字节对齐*/
    ret = posix_memalign((void**)&base, 256, 1024);
    if(ret != 0)
    {
        printf("posix_memalign error\n");
        exit(-1);
    }
    base[0] = 0;
    base[1] = 1;
    base[2] = 2;
    base[3] = 3;
    free(base);
    base = NULL;

    /*申请内存:256个字节对齐*/
    base = (int*)aligned_alloc(256, 256*4);
    if(base == NULL)
    {
        printf("aligned_alloc error\n");
        exit(-1);
    }
    base[0] = 0;
    base[1] = 1;
    base[2] = 2;
    base[3] = 3;
    free(base);
    base = NULL;

    /*申请内存:256个字节对齐*/
    base = (int*)valloc(1024);
    if(base == NULL)
    {
        printf("valloc error\n");
        exit(-1);
    }
    base[0] = 0;
    base[1] = 1;
    base[2] = 2;
    base[3] = 3;
    free(base);
    base = NULL;

    return 0;
}























#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MALLOC_MEM_SIZE (1*1024*1024)

int main()
{
    char *base = NULL;

    base = (char *)malloc(MALLOC_MEM_SIZE);
    if(base == NULL)
    {
        printf("malloc error\n");
        exit(-1);
    }

    memset(base, 0x00, MALLOC_MEM_SIZE);
    free(base);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    char buf[124] = {0};
    char *ptr;

    memset(buf, 0x00, sizeof(buf));
    ptr = getcwd(buf, sizeof(buf));
    if(ptr == NULL)
    {
        perror("getcwd error");
        exit(-1);
    }

    printf("Current working directory: %s\n", buf);
    exit(0);
}

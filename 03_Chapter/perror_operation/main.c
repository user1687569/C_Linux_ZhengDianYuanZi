#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    printf("Hello World!\n");
    perror("Hello: ");
    return 0;
}


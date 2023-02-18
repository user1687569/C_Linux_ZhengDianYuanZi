#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int fd;

    fd = open("./test_file", O_RDONLY);
    if(fd == -1)
    {
        perror("Open error");
        return -1;
    }

    close(fd);
    return 0;
}


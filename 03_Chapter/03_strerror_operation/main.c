#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int fd;

    fd = open("./test_file.txt", O_RDONLY);
    if(fd == -1)
    {
        printf("errno[int]: %d\n", errno);
        printf("error[string]: %s\n", strerror(errno));
        return -1;
    }

    close(fd);
    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int fd;

    fd = open("./test_file", O_RDONLY);
    if(fd == -1)
    {
        perror("open error");
//        _exit(-1);
//        _Exit(-1);
        exit(-1);
    }

    printf("Close file...\n");
    close(fd);
    return 0;
}

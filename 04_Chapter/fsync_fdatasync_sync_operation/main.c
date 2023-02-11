#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUF_SIZE    4096
#define READ_FILE   "./rfile"
#define WRITE_FILE  "./wfile"

static char buf[BUF_SIZE];

int main()
{
    int rfd, wfd;
    size_t size;

    rfd = open(READ_FILE, O_RDONLY);
    if(rfd < 0)
    {
        perror("open error");
        exit(-1);
    }

    wfd = open(WRITE_FILE, O_WRONLY|O_CREAT|O_TRUNC, 0664);
    if(wfd < 0)
    {
        perror("open error");
        exit(-1);
    }

    while (0 < (size = read(rfd, buf, BUF_SIZE))) {
        write(wfd, buf, size);
    }

//    fsync(wfd);
//    fdatasync(wfd);
    sync();

    close(rfd);
    close(wfd);
    exit(0);
}

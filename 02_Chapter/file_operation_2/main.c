#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd1;

    fd1 = open("./test_file.txt", O_RDONLY);
    if(fd1 == -1)
    {
        printf("Error:Open test_file.txt failed.\n");
        printf("test_file.txt does not exist.\n");
        return -1;
    }

    printf("Open test_file.txt successfully.\n");
    close(fd1);
    return 0;
}

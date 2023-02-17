#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int ret;

    ret = mkdir("./new_dir", S_IRWXU
                |S_IRGRP|S_IXGRP|
                S_IROTH|S_IXOTH);
    if(ret == -1){
        perror("mkdir error");
        printf("errno = %d\n", errno);
        if(errno == 17){
            ret = rmdir("./new_dir");
            if(ret == -1){
                perror("rmdir error");
                exit(-1);
            }
            else{
                printf("remove directory new_dir successfully!\n");
            }
        }
        else{
            exit(-1);
        }
    }
    else{
        printf("make directory new_dir successfully!\n");
    }

    exit(0);
}

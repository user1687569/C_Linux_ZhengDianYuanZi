#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ret;
    char *command = "ls /root";

    ret = system(command);
    if(ret == -1){
        fputs("system error.\n", stderr);
    }
    else{
        if(WIFEXITED(ret) && (127 == WEXITSTATUS(ret)))
            fputs("could not invoke shell.\n", stderr);
    }

    return 0;
}

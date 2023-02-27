#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    if(putenv("King=lishu")){
        perror("putenv error");
        exit(-1);
    }

    sleep(60);

    return 0;
}

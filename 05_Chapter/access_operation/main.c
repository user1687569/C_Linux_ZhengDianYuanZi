#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FILENAME    "./test_file"

int main()
{
    int ret;

    ret = access(FILENAME, F_OK);
    if(ret == -1)
    {
        printf("%s: file does not exist.\n", FILENAME);
        exit(-1);
    }

    ret = access(FILENAME, R_OK);
    if(!ret)
        printf("Read permission: Yes\n");
    else
        printf("Read permission: No\n");

    ret = access(FILENAME, W_OK);
    if(!ret)
        printf("Write permission: Yes\n");
    else
        printf("Write permission: No\n");

    ret = access(FILENAME, X_OK);
    if(!ret)
        printf("Execution permission: Yes\n");
    else
        printf("Execution permission: No\n");

    exit(0);
}

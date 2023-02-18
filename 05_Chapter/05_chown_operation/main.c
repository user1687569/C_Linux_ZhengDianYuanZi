#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int ret;
    uid_t userid;
    gid_t groupid;

    ret = chown("./test_file", 0, 0);
    if(ret == -1)
    {
        perror("chown error");
        exit(-1);
    }
    else
    {
        printf("change owner successfully!\n");
    }

    userid = getuid();
    groupid = getgid();
    printf("Process user id:%d, group id:%d\n", userid, groupid);

    exit(0);
}


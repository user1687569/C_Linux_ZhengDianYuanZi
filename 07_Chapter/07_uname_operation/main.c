#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>

int main()
{
    struct utsname os_info;
    int ret;

    /*
     * 用于获取有关当前操作系统内核的名称和信息
     */
    ret = uname(&os_info);
    if(ret == -1)
    {
        perror("uname error");
        exit(-1);
    }

    printf("操作系统名称:%s\n", os_info.sysname);
    printf("主机名:%s\n", os_info.nodename);
    printf("内核版本:%s\n", os_info.release);
    printf("发行版本:%s\n", os_info.version);
    printf("硬件架构:%s\n", os_info.machine);

    return 0;
}

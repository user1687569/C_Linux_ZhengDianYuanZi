#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

//struct sysinfo {
//    __kernel_long_t uptime;		/* Seconds since boot */
//    __kernel_ulong_t loads[3];	/* 1, 5, and 15 minute load averages */
//    __kernel_ulong_t totalram;	/* Total usable main memory size */
//    __kernel_ulong_t freeram;     /* Available memory size */
//    __kernel_ulong_t sharedram;	/* Amount of shared memory */
//    __kernel_ulong_t bufferram;	/* Memory used by buffers */
//    __kernel_ulong_t totalswap;	/* Total swap space size */
//    __kernel_ulong_t freeswap;	/* swap space still available */
//    __u16 procs;                  /* Number of current processes */
//    __u16 pad;                    /* Explicit padding for m68k */
//    __kernel_ulong_t totalhigh;	/* Total high memory size */
//    __kernel_ulong_t freehigh;	/* Available high memory size */
//    __u32 mem_unit;               /* Memory unit size in bytes */
//    char _f[20-2*sizeof(__kernel_ulong_t)-sizeof(__u32)];	/* Padding: libc5 uses this.. */
//};

int main()
{
    struct sysinfo sys_info;
    int ret;

    ret = sysinfo(&sys_info);
    if(ret == -1)
    {
        perror("sysinfo error");
        exit(-1);
    }

    printf("uptime: %ld\n", sys_info.uptime);
    printf("1 minute load average: %lu\n", sys_info.loads[0]);
    printf("5 minute load average: %lu\n", sys_info.loads[1]);
    printf("15 minute load average: %lu\n", sys_info.loads[2]);
    printf("totalram: %lu\n", sys_info.totalram);
    printf("freeram: %lu\n", sys_info.freeram);
    printf("sharedram: %lu\n", sys_info.sharedram);
    printf("bufferram: %lu\n", sys_info.bufferram);
    printf("totalswap: %lu\n", sys_info.totalswap);
    printf("procs: %u\n", sys_info.procs);
    printf("pad: %u\n", sys_info.pad);
    printf("totalhigh: %lu\n", sys_info.totalhigh);
    printf("freehigh: %lu\n", sys_info.freehigh);
    printf("mem_unit: %u\n\n", sys_info.mem_unit);

    char hostname[32] = {0};
//    bzero(hostname, 0x00);
    memset(hostname, 0x00, sizeof(hostname));
    ret = gethostname(hostname, sizeof(hostname));
    if(ret == -1)
    {
        perror("gethostname error");
        exit(ret);
    }
    puts(hostname);

    return 0;
}
















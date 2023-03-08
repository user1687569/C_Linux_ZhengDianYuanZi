#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

int main(int argc, char *argv[])
{
    char *ptr;
    for(int i = 0; i < argc; i++){
        if(i == 0){
            ptr = strrchr(argv[i], '/');
            printf("[%d]:%s, ", i, ptr + 1);
        }else{
            printf("[%d]:%s, ", i, argv[i]);
        }
    }
    printf("\n");

    int opt = 0;
    char *optstr = "a::b:c:d:e";
    while((opt = getopt(argc, argv, optstr)) != -1){
        printf("opt = %c\t\t", opt);
        printf("optarg = %s\t\t", optarg);
        printf("optind = %d\t\t", optind);
        printf("argv[optind] = %s\n", argv[optind]);
    }

    return 0;
}

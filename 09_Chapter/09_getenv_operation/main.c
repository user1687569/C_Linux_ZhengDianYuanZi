#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    const char *str_val = NULL;

    argc = 2;
    argv[0] = "getenv";
//    argv[1] = "LANG";
//    argv[1] = "PWD";
//    argv[1] = "USER";
    argv[1] = "SHELL";  /* shell解析器名称 */

    if(argc < 2){
        fprintf(stderr, "Error:请输入环境变量名称\n");
        exit(-1);
    }

    /* 获取环境变量 */
    str_val = getenv(argv[1]);
    if(str_val == NULL){
        fprintf(stderr, "Error:不存在[%s]环境变量\n", argv[1]);
        exit(-1);
    }

    /* 打印环境变量的值 */
    printf("环境变量的值:%s\n", str_val);
    exit(0);
}


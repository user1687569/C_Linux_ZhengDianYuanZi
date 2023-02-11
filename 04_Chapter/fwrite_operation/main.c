#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buf[] = "Hello World!\n";
    FILE *fp = NULL;
    int ret;

    fp = fopen("./test_file", "w");
    if(fp == NULL)
    {
        perror("fopen error");
        exit(-1);
    }

    printf("文件打开成功!\n");

    ret = fwrite(buf, 1, sizeof(buf), fp);
    if(ret < sizeof(buf))
    {
        printf("fwrite error\n");
        fclose(fp);
        exit(-1);
    }

    printf("数据写入成功!\n");
    fclose(fp);
    exit(0);
}

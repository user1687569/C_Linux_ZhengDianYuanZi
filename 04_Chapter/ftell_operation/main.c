#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = NULL;
    int ret;

    fp = fopen("./test_file", "r");
    if(fp == NULL)
    {
        perror("fopen error");
        exit(-1);
    }
    printf("文件打开成功!\n");

    if(0 > fseek(fp, 0, SEEK_END))
    {
        perror("fseek error");
        fclose(fp);
        exit(-1);
    }

    ret = ftell(fp);
    if(ret < 0)
    {
        printf("ftell error\n");
        fclose(fp);
        exit(-1);
    }
    printf("文件大小: %d个字节\n", ret);

    fclose(fp);
    exit(0);
}

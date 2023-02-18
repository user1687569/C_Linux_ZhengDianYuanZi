#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buf[50] = {0};
    FILE *fp = NULL;
    int size;

    fp = fopen("./test_file", "r");
    if(fp == NULL)
    {
        perror("fopen error");
        exit(-1);
    }

    printf("文件打开成功!\n");

    size = fread(buf, 1, 12, fp);
    if(size < 12)
    {
        printf("fread error\n");
        fclose(fp);
        exit(-1);
    }

    printf("成功读取%d个字节数据:%s\n", size, buf);
    fclose(fp);
    exit(0);
}


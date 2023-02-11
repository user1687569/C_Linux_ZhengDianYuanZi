#include <stdio.h>
#include <stdlib.h>

int main()
{
    char rd_buf[100] = {0};
    char wr_buf[] = "I am King Tree!\n";
    FILE *fp = NULL;
    int ret;

    fp = fopen("./test_file", "w+");
    if(fp == NULL)
    {
        perror("fopen error");
        exit(-1);
    }
    printf("文件打开成功!\n");

    ret = fwrite(wr_buf, 1, sizeof(wr_buf), fp);
    if(ret < sizeof(wr_buf))
    {
        printf("fwrite error\n");
        fclose(fp);
        exit(-1);
    }
    printf("数据写入成功!\n");

    if(0 > fseek(fp, 0, SEEK_SET))
    {
        perror("fseek error");
        fclose(fp);
        exit(-1);
    }

    ret = fread(rd_buf, 1, sizeof(wr_buf), fp);
    if(ret < sizeof(wr_buf))
    {
        printf("fread error\n");
        fclose(fp);
        exit(-1);
    }
    printf("成功读取%d个字节数据: %s\n", ret, rd_buf);

    fclose(fp);
    exit(0);
}


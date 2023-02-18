#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = NULL;
    char buf[20] = {0};
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

    ret = fread(buf, 1, 10, fp);
    if(ret < 10)
    {
        if(feof(fp))
        {
            printf("end-of-file标志被设置, 已到文件末尾!\n");
        }

        clearerr(fp);
    }
    else
    {
        printf("read buffer: %s\n", buf);
    }

    fclose(fp);
    exit(0);
}

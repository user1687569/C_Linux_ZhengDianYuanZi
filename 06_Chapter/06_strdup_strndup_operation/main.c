#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

int main()
{
    /*
     * Using strdup()...
     * strdup()函数是C语言中常用的一种字符串拷贝库函数，
     * 一般和free()函数成对出现
     * strdup()在内部调用了malloc()为变量分配内存，
     * 不需要使用返回的字符串时，需要用free()释放掉相应的内存空间，
     * 否则会造成内存泄露
     */
    char *s = "Golden Global View";
    char *d;

    d = strdup(s);
    if(d != NULL)
    {
        printf("strdup::%s\n", d);
        free(d);
        d = NULL;
    }

    d = strndup(s, 6);
    if(d != NULL)
    {
        printf("strndup::%s\n", d);
        free(d);
        d = NULL;
    }

    return 0;
}





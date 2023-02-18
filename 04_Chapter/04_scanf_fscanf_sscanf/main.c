#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int a;
    float b;
    char *str;

    printf("请输入一个整数:");
    scanf("%d", &a);
    printf("你输入的整数为:%d\n", a);

    printf("请输入一个浮点数:");
    scanf("%f", &b);
    printf("你输入的浮点数为:%f\n", b);

    printf("请输入一个字符串:");
    scanf("%ms", &str);
    printf("你输入的字符串为:%s\n", str);

    free(str);
    return 0;
}

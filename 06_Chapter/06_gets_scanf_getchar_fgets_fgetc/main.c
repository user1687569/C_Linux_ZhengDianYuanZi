#include <stdio.h>
#include <stdlib.h>

int main()
{
    fprintf(stdout, "Using gets()\n");
    char str[100] = {0};
    char *ptr = NULL;
    /*
     * 其实我们建议不要使用gets()函数, 因为程序中使用
     * gets()函数是非常不安全的,可能会出现bug,出现不可靠性,
     * gets()在某些意外情况下会导致程序陷入不可控状态
     */
    ptr = gets(str);
    if(ptr == NULL)
        exit(-1);
    puts(str);


    fprintf(stdout, "Using scanf()\n");
    char s1[100] = {0};
    char s2[100] = {0};
    scanf("%s", s1);
    printf("s1:%s\n", s1);
    scanf("%s", s2);
    printf("s2:%s\n", s2);


    fprintf(stdout, "Using scanf() to get a character\n");
    char s[100] = {0};
    char c;
    scanf("%s", s);
    printf("s:%s\n", s);
    scanf("%c", &c);
    printf("c:%d\n", c);


    fprintf(stdout, "Using getchar() to get a character\n");
    int ch;
    ch = getchar();
    printf("ch:%c\n", ch);

    getchar();
    fprintf(stdout, "Using fgets() to get a string\n");
    memset(str, 0x00, sizeof(str));
    fgets(str, sizeof(str), stdin);
    printf("%s\n", str);

    exit(0);
}




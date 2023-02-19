#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <regex.h>

int main()
{
    char ebuff[256] = {0};
    int ret;
    int cflags = REG_EXTENDED|REG_ICASE|REG_NOSUB;
    regex_t reg;
    char *test_str = "Hello World";
    /* 元字符, 开始^, 结尾$ */
    char *reg_str = "H.*";  /* .作为普通字符使用 */
//    char *reg_str = "^Hello";   /* 以Hello开头 */
//    char *reg_str = "World";
//    char *reg_str = "World$"; /* 以World结尾 */

    ret = regcomp(&reg, reg_str, cflags);
    if(ret)
    {
        regerror(ret, &reg, ebuff, 256);
        fprintf(stderr, "%s\n", ebuff);
        goto end;
    }

    ret = regexec(&reg, test_str, 0, NULL, 0);
    if(ret)
    {
        regerror(ret, &reg, ebuff, 256);
        fprintf(stderr, "%s\n", ebuff);
        goto end;
    }

    regerror(ret, &reg, ebuff, 256);
    fprintf(stderr, "result is:%s\n", ebuff);
end:
    regfree(&reg);

    return 0;
}

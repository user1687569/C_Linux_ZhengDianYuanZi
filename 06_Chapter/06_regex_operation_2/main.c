#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <regex.h>

int main()
{
    int i;
    char ebuff[256];
    int ret;
    int cflags;
    regex_t reg;
    regmatch_t rm[5];
    char *part_str = NULL;
    char *test_str = "Hello World";
    char *reg_str = "e(.*)o";
    static int count = 0;

    cflags = REG_EXTENDED | REG_ICASE;
    ret = regcomp(&reg, reg_str, cflags);
    if(ret)
    {
        regerror(ret, &reg, ebuff, 256);
        fprintf(stderr, "%s\n", ebuff);
        goto end;
    }

    ret = regexec(&reg, test_str, 5, rm, 0);
    if(ret)
    {
        regerror(ret, &reg, ebuff, 256);
        fprintf(stderr, "%s\n", ebuff);
        goto end;
    }

    regerror(ret, &reg, ebuff, 256);
    fprintf(stderr, "result is:%s\n", ebuff);
    for(i = 0; i < 5; i++)
    {
        if(rm[i].rm_so > -1)
        {
            part_str = strndup(test_str + rm[i].rm_so, rm[i].rm_eo - rm[i].rm_so);
            fprintf(stderr, "%s\n", part_str);
            free(part_str);
            part_str = NULL;
            count++;
            printf("Current count is:%d\n", count);
        }
    }

end:
    regfree(&reg);
    return 0;
}



































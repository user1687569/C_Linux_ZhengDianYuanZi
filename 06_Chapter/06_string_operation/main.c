#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    fprintf(stdout, "Using strlen()...\n");
    char str[] = "Linux app strlen test!";
    printf("String:\"%s\"\n", str);
    printf("Length:%ld\n", strlen(str));


    fprintf(stdout, "Using sizeof() and strlen()...\n");
    char strstr[50] = "Linux app strlen test!";
    char *ptr = strstr;
    printf("sizeof:%ld\n", sizeof(strstr));
    printf("strlen:%ld\n", strlen(strstr));
    puts("~~~~~~~~~~~~~~");
    printf("sizeof:%ld\n", sizeof(ptr));
    printf("strlen:%ld\n", strlen(ptr));

    return 0;
}

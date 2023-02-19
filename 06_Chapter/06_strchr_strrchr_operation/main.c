#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *ptr = NULL;
    char str[] = "Hello World!";

    ptr = strchr(str, 'W');
    if(ptr != NULL)
    {
        printf("Character:%c\n", *ptr);
        printf("Offset:%ld\n", ptr-str);
    }

    ptr = NULL;
    char strstr[] = "I love my home";

    ptr = strchr(strstr, 'o');
    if(ptr != NULL)
        printf("strchr:%ld\n", ptr - strstr);

    ptr = strrchr(strstr, 'o');
    if(ptr != NULL)
        printf("strrchr:%ld\n", ptr - strstr);

    exit(0);
}


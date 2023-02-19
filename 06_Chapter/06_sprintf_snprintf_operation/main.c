#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[20] = {0};

    sprintf(str, "%d", 500);
    puts(str);

    memset(str, 0x00, sizeof(str));
    sprintf(str, "%f", 500.999);
    puts(str);

    memset(str, 0x00, sizeof(str));
    sprintf(str, "%u", 500);
    puts(str);

    memset(str, 0x00, sizeof(str));
    snprintf(str, 2, "%d", 999);
    puts(str);

    return 0;
}

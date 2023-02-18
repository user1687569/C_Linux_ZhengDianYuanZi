#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100];
    memset(str, 0x00, sizeof(str));

    bzero(str, sizeof(str));
    exit(0);
}

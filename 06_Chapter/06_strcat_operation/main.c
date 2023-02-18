#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str1[100] = "Linux app strcat test!!!";
    char str2[] = "Hello World!";

    strcat(str1, str2);
    puts(str1);

    memset(str1, 0x00, sizeof(str1));
    strcpy(str1, "Linux app strcat test!!!");
    strncat(str1, str2, 5);
    puts(str1);

    return 0;
}

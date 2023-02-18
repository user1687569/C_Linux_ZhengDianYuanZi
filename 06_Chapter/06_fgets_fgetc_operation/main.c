#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[100] = {0};
    FILE *fp = NULL;

    fp = fopen("./test_file", "r");
    if(fp == NULL)
    {
        perror("fopen error");
        exit(-1);
    }

    fgets(str, sizeof(str), fp);
    printf("%s", str);

    fclose(fp);

    fprintf(stdout, "Using fgetc() to get a character...\n");
    int ch;
    ch = fgetc(stdin);
    printf("%c\n", ch);

    exit(0);
}

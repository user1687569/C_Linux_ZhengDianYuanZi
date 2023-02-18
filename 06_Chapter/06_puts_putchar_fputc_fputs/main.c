#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[50] = "Linux app puts test";

    puts("Hello World!");
    puts(str);

    putchar('A');
    putchar('B');
    putchar('C');
    putchar('D');
    putchar('\n');

    fputc('A', stdout);
    fputc('B', stdout);
    fputc('C', stdout);
    fputc('D', stdout);
    fputc('\n', stdout);

    fputs("Hello World...1\n", stdout);
    fputs("Hello World...2\n", stdout);

    /*
     * put characters to file.
     */
    FILE *fp = NULL;
    fp = fopen("./new_file", "a");
    if(fp == NULL)
    {
        perror("fopen error");
        exit(-1);
    }

    fputs("I am King Tree.\n", fp);
    fputs("Awesome\n", fp);
    fclose(fp);

    exit(0);
}



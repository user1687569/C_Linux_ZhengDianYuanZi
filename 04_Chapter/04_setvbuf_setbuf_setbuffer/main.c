#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void buffer_exist();
void buffer_no_exist();
void buffer_flush();
void buffer_flush_fclose();

int main()
{
//    buffer_no_exist();
//    buffer_flush();
    buffer_flush_fclose();
    return 0;
}


void buffer_exist()
{
    printf("Hello World!\n");
    printf("Hello World!");

    sleep(5);
    printf("\nDone!\n");
}


void buffer_no_exist()
{
    if(setvbuf(stdout, NULL, _IONBF, 0))
    {
        perror("setvbuf error");
        exit(0);
    }

    printf("Hello World!\n");
    printf("Hello World!");

    sleep(5);
    printf("\nDone!\n");
}


void buffer_flush()
{
    printf("Hello World!\n");
    printf("Hello World!");
    fflush(stdout);

    sleep(5);
    printf("\nDone!\n");
}


void buffer_flush_fclose()
{
    printf("Hello World!\n");
    printf("Hello World!");
    fclose(stdout);

    sleep(5);
    printf("\nDone!\n");//不会输出，因为关闭了stdout
}


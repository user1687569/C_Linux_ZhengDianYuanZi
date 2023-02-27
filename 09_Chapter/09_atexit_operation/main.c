#include <stdio.h>
#include <stdlib.h>


static void bye(void)
{
    puts("Goodbye!");
}


int main()
{
    if(atexit(bye)){
        fprintf(stderr, "Cannot set exit function\n");
        exit(-1);
    }

    printf("Inside main function::before exit(0)\n");
    exit(0);
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int random_number_arr[8];
    int count;

    srand(time(NULL));

    for(count = 0; count < 8; count++)
        random_number_arr[count] = rand() % 100;

    printf("[");
    for(count = 0; count < 8; count++)
    {
        printf("%d", random_number_arr[count]);
        if(count != 8-1)
            printf(",");
    }

    printf("]\n");
    return 0;
}


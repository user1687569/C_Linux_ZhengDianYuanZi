#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    clock_t t_start;
    clock_t t_end;
    int i, j;

    t_start = clock();
    if(t_start == -1)
        exit(-1);

    for(i = 0; i < 20000; i++)
        for(j = 0; j < 20000; j++)
            ;

    t_end = clock();
    if(t_end == -1)
        exit(-1);

    printf("总的CPU时间:%f\n", (t_end-t_start)/(double)CLOCKS_PER_SEC);
    return 0;
}

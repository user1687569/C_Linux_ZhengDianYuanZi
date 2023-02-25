#include <stdio.h>
#include <string.h>

int main()
{
    char input[32] = "123,245,789";
    int i, j, k;
    char *ptr;
    int index;

    index = 0;
    ptr = strtok(input, ",");
    while (ptr != NULL) {
        switch (index) {
        case 0:
            i = atoi(ptr);
            break;
        case 1:
            j = atoi(ptr);
            break;
        case 2:
            k = atoi(ptr);
            break;
        default:
            break;
        }
        ptr = strtok(NULL, ",");
        index++;
    }

    printf("i=%d,j=%d,k=%d\n", i, j, k);
    return 0;
}


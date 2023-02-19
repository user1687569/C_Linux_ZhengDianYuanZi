#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("atof:   %lf\n", atof("0.123"));
    printf("atof:   %lf\n", atof("-1.1185"));
    printf("atof:   %lf\n", atof("100.0123"));


    printf("strtof: %f\n", strtof("0.123", NULL));
    printf("strtod: %lf\n", strtod("-1.1185", NULL));
    printf("strtold:%Lf\n", strtold("100.0123", NULL));

    return 0;
}

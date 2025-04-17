#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    int precision = atoi(argv[1]);
    char format[50];
    int i;

    sprintf(format, "sqrt(%%.%df) = %%.%df\n", precision, precision);

    for (i = 2; i < argc; i++) {
        double num = atof(argv[i]);
        double result = sqrt(num);
        printf(format, num, result);
    }

    return 0;
}

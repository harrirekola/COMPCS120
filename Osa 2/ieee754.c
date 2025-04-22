#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]) {
    int i, e, sign;
    double mantissa = 1.0;
    int exponent = 0;
    const char *bin = argv[1];
    double value;

    /* Calculate mantissa */
    for (i = 9; i < 32; i++) {
        if (bin[i] == '1') {
            mantissa += pow(2, -(i - 8));
        }
    }
    printf("%.15f\n", mantissa);

    /* Calculate exponent */
    for (i = 1; i <= 8; i++) {
        exponent = exponent * 2 + (bin[i] - '0');
    }
    e = exponent - 127;
    printf("%d\n", e);

    sign = bin[0] - '0';

    /* Final value and sign */
    value = mantissa * pow(2, e);
    if (sign) value = -value;

    if(sign == 0) {
        printf("+\n");
    } else {
        printf("-\n");
    }    

    printf("%.15f\n", value);

    return 0;
}
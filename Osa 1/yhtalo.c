#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double c = atof(argv[3]);
    double result, result1, result2, upper, lower, inside;

    inside = pow(b,2) - 4*a*c;

    if(inside < 0) {
        printf("Ei ratkaisua\n");
    } else if(inside == 0) {
        result = -b / (2 * a);
        printf("%.3f\n", result);
    } else {
        upper = -b + sqrt(pow(b,2)-4 * a * c);
        lower = 2 * a;
        result1 = upper / lower;

        upper = -b - sqrt(pow(b,2)-4 * a * c);
        lower = 2 * a;
        result2 = upper / lower;

        if(result1 < result2) {
            printf("%.3f ", result1);
            printf("%.3f\n", result2);
        } else {
            printf("%.3f ", result2);
            printf("%.3f\n", result1);
        }
    }

    return 0;
}
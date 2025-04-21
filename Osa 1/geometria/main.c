#include <stdlib.h>
#include <stdio.h>
#include "geometria.h"

int main(int argc, char* argv[]) {
    int i;
    long double num, area, volume, perimeter;
    printf("Piin arvo: %.19Lf\n", PII);

    for(i = 1; i < argc; i++) {
        num = atof(argv[i]);
        area = ympyranAla(num);
        volume = pallonTilavuus(num);
        perimeter = 2 * PII * num;
        printf("Säteen %.6Lf omaavan ympyrän ala ja pallon tilavuus: %.10Lf ja %.10Lf\n", num, area, volume);
        printf("Säteen %.6Lf omaavan ympyrän piiri on %.10Lf\n", num, perimeter);
    }
    return 0;
}
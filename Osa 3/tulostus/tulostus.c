#include "tulostus.h"

void tulostaDblTaulu(double *taulu, size_t lkm, const char *taulNimi, int tarkkuus, const char *tiedNimi) {
    size_t i;

    /* Create file */
    FILE *fptr;
    fptr = fopen(tiedNimi, "w");

    if (fptr == NULL) {
        printf("Error opening file!\n");
        return;
    }

    /* Loop through values and write */
    for(i = 0; i < lkm; i++) {
        double value = taulu[i];
        fprintf(fptr, "%s[%ld] = %.*f\n", taulNimi, i, tarkkuus, value); 
    }

    fclose(fptr);
}
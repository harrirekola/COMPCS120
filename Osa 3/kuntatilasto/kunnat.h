#ifndef KUNNAT_H
#define KUNNAT_H

#include <stdio.h>
#include<stdlib.h>

typedef struct Kunta
{
    const char *nimi;
    unsigned int vakiluku;
    float pintaala;
} Kunta;

Kunta *luoKunta(const char *nimi, unsigned int vakiluku, float pintaala);

Kunta **lueKunnat(FILE *virta, size_t *lkm);

void tuhoaKunta(Kunta *k);

char *lueKunnes(FILE *virta, char *erotin);

#endif /* KUNNAT_H */

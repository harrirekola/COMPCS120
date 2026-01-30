#include "kunnat.h"
#include <stdlib.h>
#include <string.h>

char *lueKunnes(FILE *virta, int erotin, int *onnistui);

Kunta *luoKunta(const char *nimi, unsigned int vakiluku, float pintaala)
{
    Kunta *k;
    size_t len;
    char *kopio;

    k = malloc(sizeof(Kunta));
    len = strlen(nimi);
    kopio = malloc(len + 1);

    strcpy(kopio, nimi);

    k->nimi = kopio;
    k->vakiluku = vakiluku;
    k->pintaala = pintaala;

    return k;
}

Kunta **lueKunnat(FILE *virta, size_t *lkm)
{
    size_t kap;
    size_t n;
    Kunta **taulukko;
    int ok;
    char *nimi;
    char *pinta;
    char *vakiluku;
    Kunta *k;

    kap = 1;
    n = 0;
    taulukko = malloc(kap * sizeof(Kunta *));

    for (;;)
    {
        nimi = lueKunnes(virta, ';', &ok);
        if (!ok)
        {
            free(nimi);
            break;
        }

        pinta = lueKunnes(virta, ';', &ok);
        if (!ok)
        {
            free(nimi);
            free(pinta);
            break;
        }

        vakiluku = lueKunnes(virta, '\n', &ok);
        if (!ok)
        {
            free(nimi);
            free(pinta);
            free(vakiluku);
            break;
        }

        nimi[strlen(nimi) - 1] = '\0';
        k = luoKunta(nimi + 1, (unsigned int)atoi(vakiluku), (float)atof(pinta));

        free(nimi);
        free(pinta);
        free(vakiluku);

        if (n == kap)
        {
            kap *= 2;
            taulukko = realloc(taulukko, kap * sizeof(Kunta *));
        }

        taulukko[n] = k;
        n++;
    }

    taulukko = realloc(taulukko, n * sizeof(Kunta *));
    *lkm = n;
    return taulukko;
}

void tuhoaKunta(Kunta *k)
{
    free((char *)k->nimi);
    free(k);
}

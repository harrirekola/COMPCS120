#include "pikalaj.h"
#include "kolmijako.h"
#include <stdlib.h>

void pikalajittele(int alku, int loppu, int t[])
{
    int a, b;
    int koko;
    int i1, i2;
    int x, y;

    if (alku >= loppu) {
        return;
    }

    a = alku + rand() % (loppu - alku + 1);
    do {
        b = alku + rand() % (loppu - alku + 1);
    } while (b == a);

    koko = loppu - alku + 1;
    kolmijako(koko, &t[alku], a - alku, b - alku, &i1, &i2);

    x = alku + (int)i1;
    y = alku + (int)i2;

    pikalajittele(alku,       x - 1, t);
    pikalajittele(x + 1,      y - 1, t);
    pikalajittele(y + 1, loppu,     t);
}

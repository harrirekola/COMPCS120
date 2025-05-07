#ifndef KERTOTAULU_H
#define KERTOTAULU_H

typedef unsigned int uint;

typedef struct Kertotaulu {
    uint a;
    uint b;
    uint c;
    uint d;
    uint **kertotaulu;
} Kertotaulu;

Kertotaulu * luoKertotaulu(uint a, uint b, uint c, uint d);
void tuhoaKertotaulu(Kertotaulu *kt);

#endif /* KERTOTAULU_H */
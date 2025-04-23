#ifndef KUUKAUDET_H
#define KUUKAUDET_H

enum {
    KK_LKM = 12
};

enum {
    TAMMIKUU = 0,
    HELMIKUU = 1,
    MAALISKUU = 2,
    HUHTIKUU = 3,
    TOUKOKUU = 4,
    KESAKUU = 5,
    HEINAKUU = 6,
    ELOKUU = 7,
    SYYSKUU = 8,
    LOKAKUU = 9,
    MARRASKUU = 10,
    JOULUKUU = 11
};

const char KK_PAIVAT[2][KK_LKM];
const char *KK_NIMET[KK_LKM];

int karkausvuosi(int vuosiluku);
char kkPituus(const char *kkNimi, int vuosiluku);

#endif /* KUUKAUDET_ H */
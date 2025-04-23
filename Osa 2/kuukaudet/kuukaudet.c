#include <stdio.h>
#include <string.h>
#include "kuukaudet.h"

const char *KK_NIMET[KK_LKM] = {
    "tammikuu",
    "helmikuu",
    "maaliskuu",
    "huhtikuu",
    "toukokuu",
    "kesäkuu",
    "heinäkuu",
    "elokuu",
    "syyskuu",
    "lokakuu",
    "marraskuu",
    "joulukuu"
};

const char KK_PAIVAT[2][KK_LKM] = {
    /* Regular year (index 0) */
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    /* Leap year (index 1) */
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int karkausvuosi(int vuosiluku)
{
    if((vuosiluku % 4 == 0 && vuosiluku % 100 != 0) || vuosiluku % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}

char kkPituus(const char *kkNimi, int vuosiluku)
{
    int onKarkausvuosi = karkausvuosi(vuosiluku);
    int kkIndeksi = -1;
    int i;
    char kkNimiLower[100];
    int j;
    
    for (j = 0; kkNimi[j]; j++) {
        kkNimiLower[j] = (kkNimi[j] >= 'A' && kkNimi[j] <= 'Z') ? kkNimi[j] + 32 : kkNimi[j];
    }
    kkNimiLower[j] = '\0';
    
    for (i = 0; i < KK_LKM; i++) {
        if (strcmp(kkNimiLower, KK_NIMET[i]) == 0) {
            kkIndeksi = i;
            break;
        }
    }
    
    if (kkIndeksi >= 0 && onKarkausvuosi) {
        return KK_PAIVAT[1][kkIndeksi];
    } else if(kkIndeksi >= 0 && !onKarkausvuosi) {
        return KK_PAIVAT[0][kkIndeksi];
    } else {
        return -1;
    }
}
#include <stdio.h>
#include <string.h>
#include "pvm.h"

Pvm * kasvataPvm(Pvm *pvm)
{   
    int days_in_month;

    if(strcmp(pvm->vk_pv, "ma") == 0) {
        strcpy(pvm->vk_pv, "ti");
    } else if(strcmp(pvm->vk_pv, "ti") == 0) {
        strcpy(pvm->vk_pv, "ke");
    } else if(strcmp(pvm->vk_pv, "ke") == 0) {
        strcpy(pvm->vk_pv, "to");
    } else if(strcmp(pvm->vk_pv, "to") == 0) {
        strcpy(pvm->vk_pv, "pe");
    } else if(strcmp(pvm->vk_pv, "pe") == 0) {
        strcpy(pvm->vk_pv, "la");
    } else if(strcmp(pvm->vk_pv, "la") == 0) {
        strcpy(pvm->vk_pv, "su");
    } else if(strcmp(pvm->vk_pv, "su") == 0) {
        strcpy(pvm->vk_pv, "ma");
    }
    
    if (pvm->kk == 4 || pvm->kk == 6 || pvm->kk == 9 || pvm->kk == 11) {
        days_in_month = 30;
    } else if (pvm->kk == 2) {
        if ((pvm->vuosi % 4 == 0 && pvm->vuosi % 100 != 0) || (pvm->vuosi % 400 == 0)) {
            days_in_month = 29;
        } else {
            days_in_month = 28;
        }
    } else {
        days_in_month = 31;
    }
    
    pvm->pv++;
    if (pvm->pv > days_in_month) {
        pvm->pv = 1;
        pvm->kk++;
        if (pvm->kk > 12) {
            pvm->kk = 1;
            pvm->vuosi++;
        }
    }
    
    return pvm;
}

unsigned int pvmEro(const Pvm *a, const Pvm *b)
{
    int earlier_a = 0;
    unsigned int days = 0;
    Pvm temp;
    
    if (a->vuosi < b->vuosi) {
        earlier_a = 1;
    } else if (a->vuosi == b->vuosi) {
        if (a->kk < b->kk) {
            earlier_a = 1;
        } else if (a->kk == b->kk) {
            if (a->pv < b->pv) {
                earlier_a = 1;
            }
        }
    }
    
    if (earlier_a) {
        temp.pv = a->pv;
        temp.kk = a->kk;
        temp.vuosi = a->vuosi;
        strcpy(temp.vk_pv, a->vk_pv);
    } else {
        temp.pv = b->pv;
        temp.kk = b->kk;
        temp.vuosi = b->vuosi;
        strcpy(temp.vk_pv, b->vk_pv);
    }
    
    while (temp.pv != (earlier_a ? b->pv : a->pv) || 
           temp.kk != (earlier_a ? b->kk : a->kk) || 
           temp.vuosi != (earlier_a ? b->vuosi : a->vuosi)) {
        kasvataPvm(&temp);
        days++;
    }
    
    return days;
}

void tulostaPvm(Pvm *pvm)
{
    printf("%s ", pvm->vk_pv);
    printf("%i.%i.%i", pvm->pv, pvm->kk, pvm->vuosi);
}
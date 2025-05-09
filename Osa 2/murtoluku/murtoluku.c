#include <stdio.h>
#include "murtoluku.h"

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

Murtoluku teeMurtoluku(int os, int nim)
{
    Murtoluku luku;
    luku.os = os;
    luku.nim = nim;
    return luku;
}

Murtoluku supistettuML(int os, int nim)
{   
    int jakaja, sign = 1;
    Murtoluku luku;

    if(nim == 0) {
        luku.os = 0;
        luku.nim = 0;
        return luku;
    }

    if(os == 0) {
        luku.os = 0;
        luku.nim = 1;
        return luku;
    }

    if ((os < 0 && nim > 0) || (os > 0 && nim < 0)) {
        sign = -1;
    }
    
    if (os < 0) os = -os;
    if (nim < 0) nim = -nim;

    jakaja = gcd(os, nim);
    os /= jakaja;
    nim /= jakaja;
    
    luku.os = sign * os;
    luku.nim = nim;
    
    return luku;
}

Murtoluku lisaaML(Murtoluku a, Murtoluku b)
{
    Murtoluku luku;
    int numerator, denominator;
    
    numerator = a.os * b.nim + b.os * a.nim;
    denominator = a.nim * b.nim;
    
    luku = teeMurtoluku(numerator, denominator);
    luku = supistettuML(luku.os, luku.nim);
    
    return luku;
}

Murtoluku vahennaML(Murtoluku a, Murtoluku b)
{
    Murtoluku luku;
    int numerator, denominator;
    
    numerator = a.os * b.nim - b.os * a.nim;
    denominator = a.nim * b.nim;
    
    luku = teeMurtoluku(numerator, denominator);
    luku = supistettuML(luku.os, luku.nim);
    
    return luku;
}

Murtoluku kerroML(Murtoluku a, Murtoluku b)
{
    Murtoluku luku;
    int numerator, denominator;
    
    numerator = a.os * b.os;
    denominator = a.nim * b.nim;
    
    luku = teeMurtoluku(numerator, denominator);
    luku = supistettuML(luku.os, luku.nim);
    
    return luku;
}

Murtoluku jaaML(Murtoluku a, Murtoluku b)
{
    Murtoluku luku;
    int numerator, denominator;

    if (b.os == 0) {
        luku.os = 0;
        luku.nim = 0;
        return luku;
    }
    
    numerator = a.os * b.nim;
    denominator = a.nim * b.os;
    
    luku = teeMurtoluku(numerator, denominator);
    luku = supistettuML(luku.os, luku.nim);
    
    return luku;
}

void tulostaML(Murtoluku ml)
{
    if (ml.nim == 0) {
        printf("undefined");
        return;
    }
    
    if (ml.nim == 1) {
        printf("%d", ml.os);
    } else {
        printf("%d/%d", ml.os, ml.nim);
    }
}
#include "bitit.h"
#include <stdio.h>

void scharBitit(signed char x) {
    int i;
    int ones = 0, zeros = 0;
    unsigned char mask = 1 << 7;

    printf("%d\n", x);
    for(i = 0; i < 8; i++) {
        if(x & mask) {
            putchar('1');
            ones++;
        } else {
            putchar('0');
            zeros++;
        }
        mask >>= 1;
    }
    putchar('\n');
    printf("%d\n", zeros);
    printf("%d\n", ones);

}

void shortBitit(short int x) {
    int i;
    int ones = 0, zeros = 0;
    unsigned short mask = 1 << 15;

    printf("%d\n", x);

    for(i = 0; i < 16; i++) {
        if(x & mask) {
            putchar('1');
            ones++;
        } else {
            putchar('0');
            zeros++;
        }
        mask >>= 1;
    }
    putchar('\n');

    printf("%d\n", zeros);
    printf("%d\n", ones);
}

void intBitit(int x) {
    int i;
    int ones = 0, zeros = 0;
    unsigned int mask = 1 << 31;

    printf("%d\n", x);

    for(i = 0; i < 32; i++) {
        if(x & mask) {
            putchar('1');
            ones++;
        } else {
            putchar('0');
            zeros++;
        }
        mask >>= 1;
    }
    putchar('\n');

    printf("%d\n", zeros);
    printf("%d\n", ones);
}

void longBitit(long int x) {
    int i;
    int ones = 0, zeros = 0;
    unsigned long int mask = 1UL << 63;

    printf("%ld\n", x);

    for(i = 0; i < 64; i++) {
        if(x & mask) {
            putchar('1');
            ones++;
        } else {
            putchar('0');
            zeros++;
        }
        mask >>= 1;
    }
    putchar('\n');

    printf("%d\n", zeros);
    printf("%d\n", ones);
}

int main(void) {
    return 0;
}
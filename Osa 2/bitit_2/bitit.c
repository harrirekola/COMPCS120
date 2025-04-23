#include <stdio.h>

void kaannaScharBitit(signed char *x) {
    unsigned char u = (unsigned char)*x;
    unsigned char reversed = 0;
    int i;

    for (i = 0; i < 8; i++) {
        reversed <<= 1;
        reversed |= (u & 1);
        u >>= 1;
    }

    *x = (signed char)reversed;
}

void kaannaShortBitit(short *x) {
    short original = *x;
    short reversed = 0;
    int i;

    for (i = 0; i < 16; i++) {
        short bit = (original >> i) & 1;

        reversed |= (bit << (15 - i));
    }

    *x = reversed;
}

void kaannaIntBitit(int *x) {
    int original = *x;
    int reversed = 0;
    int i;

    for (i = 0; i < 32; i++) {
        int bit = (original >> i) & 1;

        reversed |= (bit << (32 - 1 - i));
    }

    *x = reversed;
}

void kaannaLongBitit(long *x) {
    long original = *x;
    long reversed = 0;
    int i;

    for (i = 0; i < 64; i++) {
        long bit = (original >> i) & 1;
        reversed |= (bit << (64 - 1 - i));
    }

    *x = reversed;
}

int main(void) {
    return 0;
}
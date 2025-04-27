#include <stdio.h>
#include <limits.h>
#include <string.h>

int anagrammeja(char mj1[], char mj2[])
{
    int i;
    int count[UCHAR_MAX+1] = {0};

    for(i = 0; mj1[i] != '\0'; i++) {
        count[(unsigned char)mj1[i]]++;
        count[(unsigned char)mj2[i]]--;
    }

    for(i = 0; i <= UCHAR_MAX; i++) {
        if(count[i] != 0) {
            return 0;
        }
    }
    return 1;
}
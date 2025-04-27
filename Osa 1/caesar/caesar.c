#include <stdio.h>
#include <limits.h>
#include <string.h>

void caesarKoodaa(char mj[], char aakkosto[], char korvaavat[])
{
    int i, j;
    char replace[UCHAR_MAX+1];
    size_t replace_size = sizeof(replace);
    size_t abc_size = strlen(aakkosto);

    for(i = 0; i < replace_size; i++) {
        replace[i] = i;
    }

    for(i = 0; i < abc_size; i++) {
        replace[(unsigned char)aakkosto[i]] = korvaavat[i];
    }

    for(j = 0; mj[j] != '\0'; j++) {
        mj[j] = replace[(unsigned char)mj[j]];
    }
}
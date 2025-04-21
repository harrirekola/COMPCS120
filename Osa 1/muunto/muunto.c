#include <ctype.h>
#include <string.h>
#include "muunto.h"

void muunna(char mj[]) {
    int i, l = 0;
    int length = strlen(mj);
    char t;

    for(i = 0; i < length; i++) {
        if (isupper(mj[i])) {
            mj[i] = tolower(mj[i]);
        } else if (islower(mj[i])) {
            mj[i] = toupper(mj[i]);
        }
    }

    while (l < length / 2) {
        t = mj[l];
        mj[l] = mj[length - 1 - l];
        mj[length - 1 - l] = t;
        l++;
    }
}

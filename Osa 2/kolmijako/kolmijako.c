#include "kolmijako.h"

IntPari kolmijako(unsigned int n, int t[], int vipu1, int vipu2, int *p1, int *p2) {
    IntPari tulos;
    int temp;
    int i;
    int pienet1 = 0, pienet2;

    if (t[vipu1] > t[vipu2]) {
        temp = vipu1;
        vipu1 = vipu2;
        vipu2 = temp;
    }

    for (i = 0; i < (int)n; i++) {
        if (t[i] < t[vipu1]) {
            if (i != pienet1) {
                if (i == vipu1) vipu1 = pienet1;
                else if (pienet1 == vipu1) vipu1 = i;
                if (i == vipu2) vipu2 = pienet1;
                else if (pienet1 == vipu2) vipu2 = i;

                temp = t[i];
                t[i] = t[pienet1];
                t[pienet1] = temp;
            }
            pienet1++;
        }
    }

    if (vipu1 != pienet1) {
        if (vipu2 == pienet1) vipu2 = vipu1;
        temp = t[pienet1];
        t[pienet1] = t[vipu1];
        t[vipu1] = temp;
        vipu1 = pienet1;
    }

    pienet2 = pienet1 + 1;
    for (i = pienet2; i < (int)n; i++) {
        if (t[i] < t[vipu2]) {
            if (i != pienet2) {
                if (i == vipu2) vipu2 = pienet2;
                else if (pienet2 == vipu2) vipu2 = i;

                temp = t[i];
                t[i] = t[pienet2];
                t[pienet2] = temp;
            }
            pienet2++;
        }
    }

    if (vipu2 != pienet2) {
        temp = t[pienet2];
        t[pienet2] = t[vipu2];
        t[vipu2] = temp;
        vipu2 = pienet2;
    }

    *p1 = pienet1;
    *p2 = pienet2;

    tulos.x = pienet1;
    tulos.y = pienet2;
    return tulos;
}

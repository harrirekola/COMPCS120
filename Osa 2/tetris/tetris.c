#include "tetris.h"

void paivita(char ruudukko[20][10])
{
    int i, j, l, k;

    for(i = 0; i < 20; i++) {
        int all_same = 1;

        if(ruudukko[i][0] == ' ') {
            continue;
        }

        for(j = 0; j < 10; j++) {
            if (ruudukko[i][j] != ruudukko[i][0]) {
                all_same = 0;
                break;
            }
        }

        if(all_same) {
            for (k = i; k > 0; k--) {
                for (l = 0; l < 10; l++) {
                    ruudukko[k][l] = ruudukko[k-1][l];
                }
            }
            
            for (l = 0; l < 10; l++) {
                ruudukko[0][l] = ' ';
            }

            i--;
        }
    }
}
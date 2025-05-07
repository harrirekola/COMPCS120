#include <stdio.h>
#include <stdlib.h>
#include "kertotaulu.h"

Kertotaulu * luoKertotaulu(uint a, uint b, uint c, uint d)
{   
    uint i, j, rows, cols;
    Kertotaulu *kt = malloc(sizeof(Kertotaulu));
    if (!kt) {
        return NULL;
    }

    kt->a = a;
    kt->b = b;
    kt->c = c;
    kt->d = d;

    cols = b - a + 2;
    rows = d - c + 2;

    kt->kertotaulu = malloc(rows * sizeof(uint *));
    if (!kt->kertotaulu) {
        free(kt);
        return NULL;
    }

    for (i = 0; i < rows; i++) {
        kt->kertotaulu[i] = malloc(cols * sizeof(uint));
        if (!kt->kertotaulu[i]) {
            for (j = 0; j < i; j++) {
                free(kt->kertotaulu[j]);
            }
            free(kt->kertotaulu);
            free(kt);
            return NULL;
        }
        
        if (i == 0) {
            kt->kertotaulu[0][0] = 0;
            for (j = 1; j < cols; j++) {
                kt->kertotaulu[0][j] = a + j - 1;
            }
        } else {
            kt->kertotaulu[i][0] = c + i - 1;
            for (j = 1; j < cols; j++) {
                kt->kertotaulu[i][j] = (c + i - 1) * (a + j - 1);
            }
        }
    }
        
    return kt;
}

void tuhoaKertotaulu(Kertotaulu *kt)
{   
    uint i, rows;

    if (!kt) {
        return;
    }
    
    rows = kt->d - kt->c + 2;
    
    for (i = 0; i < rows; i++) {
        free(kt->kertotaulu[i]);
    }
    
    free(kt->kertotaulu);
    free(kt);
}

int main(int argc, char *argv[])
{
  Kertotaulu *kt = luoKertotaulu(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
  uint i = 0;
  uint j = 0;
  for(i = 0; i <= (kt->d - kt->c + 1); ++i)    /* Rivit */
  {
    for(j = 0; j <= (kt->b - kt->a + 1); ++j)  /* Sarakkeet */
    {
      if((i > 0) || (j > 0)) /* Onko kyseessä muu kuin kohta [0][0]? */
      {
         printf("%4u", kt->kertotaulu[i][j]); /* 4 merkin leveys. */
      }
      else
      {
         printf("    "); /* Kohtaan [0][0] vain 4 välilyöntiä. */
      }
    }
    printf("\n");
  }
  tuhoaKertotaulu(kt);
  return 0;
}
#include <stdio.h>
#include "utf8.h"

unsigned int count_bits_needed(unsigned int x) {
    unsigned int bits;
    if (x == 0) return 1;
    
    bits = 0;
    while (x > 0) {
        x >>= 1;
        bits++;
    }
    return bits;
}

void utf8_koodaa(unsigned int merkki, unsigned char utf8[])
{
    unsigned int bits_needed;
    bits_needed = count_bits_needed(merkki);
    utf8[0] = utf8[1] = utf8[2] = utf8[3] = 0;
    utf8[4] = '\0';
    
    if (bits_needed <= 7) {
        utf8[0] = merkki & 127;
    } 
    else if (bits_needed <= 11) {
        utf8[0] = ((merkki >> 6) & 31) | 192;
        utf8[1] = (merkki & 63) | 128;
    } 
    else if (bits_needed <= 16) {
        utf8[0] = ((merkki >> 12) & 15) | 224;
        utf8[1] = ((merkki >> 6) & 63) | 128;
        utf8[2] = (merkki & 63) | 128;
    } 
    else if (bits_needed <= 21) {
        utf8[0] = ((merkki >> 18) & 7) | 240;
        utf8[1] = ((merkki >> 12) & 63) | 128;
        utf8[2] = ((merkki >> 6) & 63) | 128;
        utf8[3] = (merkki & 63) | 128;
    }
}

int main(void)
{
  unsigned int koodit[6] = {228, 49340, 49457, 12477, 12491, 12540};
  unsigned char utf8[5];
  int i = 0;
  for(i = 0; i < 6; ++i)
  {
    utf8_koodaa(koodit[i], utf8);
    printf("%s\n", utf8);
  }
  return 0;
}
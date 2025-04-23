#include <stdio.h>
#include <stdlib.h>
#include "vaihto.h"

void vaihda(int *a, int *b)
{
    int temp_a = *a;
    *a = *b;
    *b = temp_a;
}

void jarjesta(int *a, int *b, int *c)
{   
    if (*a > *b) vaihda(a, b);
    if (*a > *c) vaihda(a, c);
    if (*b > *c) vaihda(b, c);
}
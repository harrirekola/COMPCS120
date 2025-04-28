#include <stdio.h>
#include <stdlib.h>
#include "fibonacci.h"

unsigned int * fib_jono(unsigned int n)
{
    int i;
    int t1 = 0, t2 = 1;
    int nextTerm = t1 + t2;
    unsigned int *arr = (unsigned int *)malloc(n * sizeof(unsigned int));
    if (arr == NULL) {
        return NULL;
    }
    arr[0] = 0;
    arr[1] = 1;

    for (i = 2; i < n; i++) {
        nextTerm = t1 + t2;
        arr[i] = nextTerm;
        t1 = t2;
        t2 = nextTerm;
      }
    return arr;
}
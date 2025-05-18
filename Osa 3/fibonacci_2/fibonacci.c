#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fibonacci.h"

char * fib_jono_mj(unsigned int n)
{   
    int i;
    int t1 = 0, t2 = 1;
    int nextTerm;
    size_t kap = 1;
    size_t pit = 0;
    char* mj;
    int m;

    mj = malloc(kap);
    if (!mj) return NULL;
    mj[0] = '\0';

    if (n == 0) {
        return mj;
    }

    if (n >= 1) {
        m = snprintf(NULL, 0, "%d", t1) + 1;
        
        if (pit + m > kap) {
            while (pit + m > kap) {
                kap = 2 * kap;
            }
            mj = realloc(mj, kap);
            if (!mj) return NULL;
        }
        
        pit += sprintf(&mj[pit], "%d", t1);
    }

    if (n >= 2) {
        m = snprintf(NULL, 0, ", %d", t2) + 1;
        
        if (pit + m > kap) {
            while (pit + m > kap) {
                kap = 2 * kap;
            }
            mj = realloc(mj, kap);
            if (!mj) return NULL;
        }
        
        pit += sprintf(&mj[pit], ", %d", t2);
    }
    
    for (i = 3; i <= n; i++) {
        nextTerm = t1 + t2;
        
        m = snprintf(NULL, 0, ", %d", nextTerm) + 1;
        
        if (pit + m > kap) {
            while (pit + m > kap) {
                kap = 2 * kap;
            }
            mj = realloc(mj, kap);
            if (!mj) return NULL;
        }
        
        pit += sprintf(&mj[pit], ", %d", nextTerm);
        
        t1 = t2;
        t2 = nextTerm;
    }
    
    mj = realloc(mj, pit + 1);
    
    return mj;
}
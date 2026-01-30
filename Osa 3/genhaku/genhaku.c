#include "genhaku.h"
#include <stdlib.h>
#include <string.h>

size_t etsi(void *mista, size_t n, void *mita, size_t m, size_t koko) {
    size_t i;
    char *mista_element = (char *)(mista);
    char *mita_element = (char *)(mita);

    for(i = 0; i <= n - m; i++) {
        if(memcmp(mista_element + (i * koko), mita_element, m * koko) == 0) {
            return i;
        }
    }
    return n;
}
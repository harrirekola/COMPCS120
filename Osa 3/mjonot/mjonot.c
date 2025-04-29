#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char ** kopioi_mjt(char **mjt, size_t lkm)
{   
    int i;
    char **arr = malloc(lkm * sizeof(char *));

    for(i = 0; i < lkm; i++) {
        char *copy = malloc(strlen(mjt[i]) * sizeof(char) + 1);
        arr[i] = copy;
        strcpy(arr[i], mjt[i]);
    }
    return arr;
}
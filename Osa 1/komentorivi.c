#include <stdio.h>
#include <string.h>

int main(int argc, char* args[]) {
    int i;

    for(i = 1; i < argc; i++) {
        printf("%d: %s (pituus: %u)\n", i, args[i], (unsigned int)strlen(args[i]));
    }
    return 0;
}
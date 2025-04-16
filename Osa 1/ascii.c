#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int i;
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    for (i = a; i <= b; i++) {
        if (i >= 32 && i <= 127) {
            printf("%d: %c\n", i, (char)i);
        }
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int i, first = 1;

    if (argc < 4) {
        return 0;
    }

    for (; a <= b; a++) {
        int is_valid = 1;
        for (i = 3; i < argc; i++) {
            if (a % atoi(argv[i]) == 0) {
                is_valid = 0;
                break;
            }
        }
        if (is_valid) {
            if (!first) {
                printf(" ");
            }
            printf("%d", a);
            first = 0;
        }
    }

    if (!first) {
        printf("\n");
    }

    return 0;
}

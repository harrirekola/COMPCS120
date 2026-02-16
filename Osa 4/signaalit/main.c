#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "signaalit.h"

int main(int argc, char **argv) {
    char input[100];
    int a, b, i, output;
    int count = 0;
    unsigned int idx;
    int *arr = NULL;
    int *temp = NULL;

    signal(SIGFPE, hoidaSIGFPE);
    signal(SIGSEGV, hoidaSIGSEGV);

    while (fgets(input, 100, stdin) != NULL) {
        input[strcspn(input, "\n")] = 0;
        
        switch (setjmp(paluuTila)) {
            case 0:
                if (sscanf(input, "lisää %d %d", &a, &b) == 2) {
                    output = a / b;
                    temp = (int*) realloc(arr, (count + 1) * sizeof(int));
                    if (temp == NULL) {
                        break;
                    }
                    arr = temp;
                    arr[count++] = output;
                } else if (sscanf(input, "tulosta %u", &idx) == 1) {
                    printf("%d\n", arr[idx]);
                } else if (strcmp(input, "tulosta") == 0) {
                    for(i = 0; i < count; i++) {
                        printf("%d%s", arr[i], (i < count - 1) ? " " : "");
                    }
                    printf("\n");
                } else {
                    free(arr);
                    return 0;
                }
                break;

            case SIGFPE:
                printf("Aiheutui signaali SIGFPE\n");
                break;

            case SIGSEGV:
                printf("Aiheutui signaali SIGSEGV\n");
                break;

            default:
                printf("Aiheutui signaali UNKNOWN\n");
                break;
        }
    }
        
    free(arr);
    return 0;
}
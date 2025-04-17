#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int count_common_elements(int a[], int size_a, int b[], int size_b, int common[]) {
    int i, j;
    int count = 0;
    for (i = 0; i < size_a; i++) {
        for (j = 0; j < size_b; j++) {
            if (a[i] == b[j]) {
                common[count++] = a[i];
                break;
            }
        }
    }
    return count;
}

int main(int argc, char *argv[]) {
    int half = (argc - 1) / 2;
    int *voittorivi = malloc(half * sizeof(int));
    int *lottorivi = malloc(half * sizeof(int));
    int *common = malloc(half * sizeof(int));
    int i, correct;

    for (i = 0; i < half; i++) {
        voittorivi[i] = atoi(argv[i + 1]);
    }

    for (i = 0; i < half; i++) {
        lottorivi[i] = atoi(argv[i + 1 + half]);
    }

    printf("Voittorivi:");
    for (i = 0; i < half; i++) {
        printf(" %d", voittorivi[i]);
    }
    printf("\n");

    printf("Lottorivi:");
    for (i = 0; i < half; i++) {
        printf(" %d", lottorivi[i]);
    }
    printf("\n");

    correct = count_common_elements(lottorivi, half, voittorivi, half, common);

    if(correct == 0) {
        printf("Ei yhtään oikein!");
    } else {
        printf("%d oikein:", correct);
        for (i = 0; i < correct; i++) {
            printf(" %d", common[i]);
        }    
    }
    printf("\n");

    free(voittorivi);
    free(lottorivi);

    return 0;
}

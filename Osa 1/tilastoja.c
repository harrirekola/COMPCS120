#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char* argv[]) {
    int i, j, count;
    double num, res;
    int found_unique = 0, max_count = 0;
    bool printed_header = false, already_printed = false;

    /* Find minimum value */
    res = atof(argv[1]);
    for(i = 1; i < argc; i++) {
        num = atof(argv[i]);
        if(num < res) {
            res = num;
        }
    }
    printf("Pienin: %f\n", res);

    /* Find maximum value */
    res = atof(argv[1]);
    for(i = 1; i < argc; i++) {
        num = atof(argv[i]);
        if(num > res) {
            res = num;
        }
    }
    printf("Suurin: %f\n", res);

    /* Find unique values */
    for (i = 1; i < argc; i++) {
        num = atof(argv[i]);
        count = 0;
        for (j = 1; j < argc; j++) {
            if (atof(argv[j]) == num) {
                count++;
            }
        }
        if (count == 1) {
            if (!found_unique) {
                printf("Ainutlaatuiset:");
                found_unique = 1;
            }
            printf(" %f", num);
        }
    }

    if (found_unique) {
        printf("\n");
    }

    /* Find most frequent values */
    for (i = 1; i < argc; i++) {
        num = atof(argv[i]);
        count = 0;
        for (j = 1; j < argc; j++) {
            if (atof(argv[j]) == num) {
                count++;
            }
        }
        if (count > max_count) {
            max_count = count;
        }
    }

    if (max_count > 1) {
        for (i = 1; i < argc; i++) {
            num = atof(argv[i]);
            already_printed = false;
            
            for (j = 1; j < i; j++) {
                if (atof(argv[j]) == num) {
                    already_printed = true;
                    break;
                }
            }
            
            if (!already_printed) {
                count = 0;
                for (j = 1; j < argc; j++) {
                    if (atof(argv[j]) == num) {
                        count++;
                    }
                }
                
                if (count == max_count) {
                    if (!printed_header) {
                        printf("Useimmiten esiintyneet (%d kertaa):", max_count);
                        printed_header = true;
                    }
                    printf(" %f", num);
                }
            }
        }
        if (printed_header) {
            printf("\n");
        }
    }

    return 0;
}
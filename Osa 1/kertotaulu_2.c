#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int col_start = atoi(argv[1]);
    int col_end = atoi(argv[2]);
    int row_start = atoi(argv[3]);
    int row_end = atoi(argv[4]);
    
    int i, j, width;

    /* Calculate the spacing width */
    int max_val = row_end * col_end;
    char spacing_buffer[20];
    sprintf(spacing_buffer, "%d", max_val);
    width = strlen(spacing_buffer) + 1;

    /* Print top header row */
    printf("%*s", width, "");
    for (j = col_start; j <= col_end; j++) {
        printf("%*d", width, j);
    }
    printf("\n");

    /* Print table rows */
    for (i = row_start; i <= row_end; i++) {
        printf("%*d", width, i);
        for (j = col_start; j <= col_end; j++) {
            printf("%*d", width, i * j);
        }
        printf("\n");
    }


    return 0;
}
#include <stdio.h>
#include <string.h>
#include <math.h>

/* Finds number of digits of a non-negative integer */
int int_length(int n) {
    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        n = -n;
    }
    return (int)log10((double)n) + 1;
}

int main(int argc, char* argv[]) {
    int i, j;
    int longest_param;
    int index_len;
    int total_width;
    int col1_width, col2_width;
    int cur_len;
    int idx, idx_digits;
    int pad_left, pad_right;
    int param_len;

    /* Determine the longest parameter string length */
    longest_param = (int)strlen(argv[1]);
    for (i = 2; i < argc; i++) {
        cur_len = (int)strlen(argv[i]);
        if (cur_len > longest_param) {
            longest_param = cur_len;
        }
    }

    /* Number of digits in the highest index */
    index_len = int_length(argc - 1);

    col1_width = index_len + 2;
    col2_width = longest_param + 2;
    total_width = col1_width + col2_width + 3;

    /* Top border */
    for (i = 0; i < total_width; i++) {
        putchar('#');
    }
    putchar('\n');

    /* Rows */
    for (i = 1; i < argc; i++) {
        idx = i;
        idx_digits = int_length(idx);
        pad_left = col1_width - idx_digits - 2;
        param_len = (int)strlen(argv[i]);
        pad_right = col2_width - param_len - 2;

        putchar('#');
        putchar(' ');
        for (j = 0; j < pad_left; j++) {
            putchar(' ');
        }
        printf("%d", idx);
        putchar(' ');
        putchar('|');
        putchar(' ');
        printf("%s", argv[i]);
        for (j = 0; j < pad_right; j++) {
            putchar(' ');
        }
        putchar(' ');
        putchar('#');
        putchar('\n');

        /* Separator line */
        if (i < argc - 1) {
            putchar('#');
            for (j = 0; j < col1_width; j++) {
                putchar('-');
            }
            putchar('+');
            for (j = 0; j < col2_width; j++) {
                putchar('-');
            }
            putchar('#');
            putchar('\n');
        }
    }

    /* Bottom border */
    for (i = 0; i < total_width; i++) {
        putchar('#');
    }
    putchar('\n');

    return 0;
}

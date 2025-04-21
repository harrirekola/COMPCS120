#include <stdio.h>
#include <string.h>

int binary_to_decimal(const char *binary) {
    int i;
    int result = 0;
    int length = strlen(binary);
    int is_negative = (binary[0] == '1');

    for (i = 0; i < length; i++) {
        result = result * 2 + (binary[i] - '0');
    }

    if (is_negative) {
        int max = 1 << length;
        result -= max;
    }

    return result;
}

int main(int argc, char* argv[]) {
    const char* binary_input = argv[1];
    int decimal = binary_to_decimal(binary_input);
    printf("%d\n", decimal);
    return 0;
}
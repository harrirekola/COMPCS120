#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Reverses a string*/
void reverse(char* s) {
    int l = 0;
    int r = strlen(s) - 1;
    char t;

    while(l < r) {
        t = s[l];
        s[l] = s[r];
        s[r] = t;

        l++;
        r--;
    }
}

/* Converts whole string to upper */
void toUpperStr(char* s) {
    int i;
    for (i = 0; s[i]; i++) {
        s[i] = toupper((unsigned char)s[i]);
    }
}

int main(int argc, char* argv[]) {
    int i;
    char originalUpper[50], reversedUpper[50];

    for(i = 1; i < argc; i++) {
        char* input = argv[i];

        strncpy(originalUpper, input, 50 - 1);
        originalUpper[50 - 1] = '\0';

        strncpy(reversedUpper, input, 50 - 1);
        reversedUpper[50 - 1] = '\0';

        toUpperStr(originalUpper);
        toUpperStr(reversedUpper);
        reverse(reversedUpper);

        if(strcmp(originalUpper, reversedUpper) != 0) {
            printf("\"%s\": ei ole palindromi\n", input);
        } else {
            printf("\"%s\": on palindromi\n", input);
        }
    }

    return 0;
}
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int i, argument, first_type;

    for(i = 1; i < argc; i++) {
        argument = atoi(argv[i]);
        printf("%d: ", argument);
        
        first_type = 1;
        
        if(argument >= SCHAR_MIN && argument <= SCHAR_MAX) {
            printf("signed char");
            first_type = 0;
        }
        
        if(argument >= 0 && argument <= UCHAR_MAX) {
            if(!first_type) printf(", ");
            printf("unsigned char");
            first_type = 0;
        }
        
        if(argument >= SHRT_MIN && argument <= SHRT_MAX) {
            if(!first_type) printf(", ");
            printf("short int");
            first_type = 0;
        }
        
        if(argument >= 0 && argument <= USHRT_MAX) {
            if(!first_type) printf(", ");
            printf("unsigned short int");
            first_type = 0;
        }
        
        if(argument >= INT_MIN && argument <= INT_MAX) {
            if(!first_type) printf(", ");
            printf("int");
        }
        
        printf("\n");
    }
    
    return 0;
}
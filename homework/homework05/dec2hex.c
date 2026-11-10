 /* converts a base-10 number from the commmand line to its 32-bit or 64-bit hexadecimal equivalent */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <errno.h>
 #include <limits.h>

 int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        fprintf(stderr, "Usage: %s <non-negative base-10 number> [8|16]\n", argv[0]);
        return 1; 
    }

/* optional digit count, defaulting to 32 bit*/

    int digits = 8; 
    if (argc == 3) {
        if (strcmp(argv[2], "8") == 0) {
            digits = 8;
        } else if (strcmp(argv[2], "16") == 0) {
            digits = 16; 
        } else {
            fprintf(stderr, "Error: Invalid digit count.\n");
            return 1; 
        }
    }

    if (argv[1][0] == '-') {
        fprintf(stderr, "Error: Negative input not allowed.\n");
        return 1; 
    }

    char *end; 
    errno = 0; 
    unsigned long long value = strtoull(argv[1], &end, 10);

    if (end == argv[1] || *end != '\0') {
        fprintf(stderr, "Error: Invalid input: %s\n", argv[1]);
        return 1; 
    }
    if (errno == ERANGE) {
        fprintf(stderr, "Error: Input too large.\n");
        return 1; 
    }
    if (digits == 8) {
        if (value > UINT_MAX) {
            fprintf(stderr, "Error: %llu is too large for 32 bits; use 16 digits.\n", value);
            return 1;
        }
        /* %08X: uppercase hex, zero-padded to 8 digits */
        printf("0x%08X\n", (unsigned int)value);
    } else {
        /* %016llX: uppercase hex, zero-padded to 16 digits */
        printf("0x%016llX\n", value);
    }

    return 0;
}
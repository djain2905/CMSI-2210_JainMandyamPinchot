/* converts a base-10 number from the command line to its 32-bit binary equivalent */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <non-negative base-10 number>\n", argv[0]);
        return 1;
    }

/* reject negative input up front*/

    if (argv[1][0] == '-') {
        fprintf(stderr, "Error: Negative input not allowed\n");
        return 1;
    }

    char *end; 
    errno =0; 
    unsigned long parsed = strtoull(argv[1], &end, 10);

    if (end == argv[1] || *end != '\0') {
        fprintf(stderr, "Error: Invalid input: %s\n", argv[1]);
        return 1; 
    }
    if (errno == ERANGE || parsed > UINT_MAX) {
        fprintf(stderr, "Error: Input too large\n", UINT_MAX);
        return 1; 
    }

    unsigned int value = (unsigned int)parsed;

/* walk from the most significant bit to the least significant bit*/

    for (int bit = 31; bit >= 0; bit--) {
        putchar(((value >> bit) & 1u) ? '1' : '0');
    }
    putchar('\n');

    return 0; 
}

    

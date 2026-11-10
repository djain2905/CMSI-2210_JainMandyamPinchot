/* prints the times tables from 2 to N in a neatly aligned grid*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_N 1000

/* number of decimal digits in a positive value*/
static int numDigits(unsigned long value) {
    int count = 1; 
    while (value >= 10) {
        value /= 10; 
        count++;
    }
    return count; 
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <N> (N >= 2)\n", argv[0]);
        return 1;
    }
    char *end; 
    errno = 0; 
    long n = strtol(argv[1], &end, 10); 

    if (end == argv [1] || *end != '\0' || errno == ERANGE) {
        fprintf(stderr, "Error: '%s' is not  a valid integer.\n", argv[1]); 
        return 1; 
    }
    if (n < 2 || n > MAX_N) {
        fprintf(stderr, "Error: N must be between 2 and %d.\n", MAX_N);
        return 1;
    }
/* The widest value in the table is N*N. Each cell is printed with
     * one space before and one after, so the field is that width + 2. */
    int width = numDigits((unsigned long)(n * n));
 
    printf(" %*s |", width, "x");
    for (long col = 2; col <= n; col++) {
        printf(" %*ld ", width, col);
    }
    putchar('\n');
 
    /* Separator line under the header. */
    long lineLen = (width + 2) + 1 + (n - 1) * (width + 2);
    for (long i = 0; i < lineLen; i++) {
        putchar(i == width + 2 ? '+' : '-');
    }
    putchar('\n');
 
    /* Body: one row per multiplier from 2 to N. */
    for (long row = 2; row <= n; row++) {
        printf(" %*ld |", width, row);
        for (long col = 2; col <= n; col++) {
            printf(" %*ld ", width, row * col);
        }
        putchar('\n');
    }
 
    return 0;
}
